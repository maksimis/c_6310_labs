#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// === 1. Обычный enum для состояния философа ===
typedef enum e_state
{
    THINKING,
    HUNGRY,
    EATING
} t_state;

// === 2. Флаговый enum для вилок в руках ===
typedef enum e_philo_flags
{
    PHILO_NONE      = 0,
    PHILO_HAS_LEFT  = 1 << 0,
    PHILO_HAS_RIGHT = 1 << 1
} t_philo_flags;

// === 3. Структура философа ===
typedef struct s_philosopher
{
    int             id;
    t_state         state;
    t_philo_flags   flags;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int             meals_eaten;
    int             max_meals;
} t_philosopher;

// === 4. Глобальная структура стола ===
typedef struct s_table
{
    int             num_philosophers;
    t_philosopher   *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t  print_mutex;
    int             running;
} t_table;

t_table *g_table = NULL;

// === 5. Безопасный вывод (исправлен) ===
void safe_print(t_philosopher *philo, const char *action)
{
    pthread_mutex_lock(&g_table->print_mutex);
    printf("Philosopher %d %s\n", philo->id + 1, action);
    pthread_mutex_unlock(&g_table->print_mutex);
}

// === 6. Обновление состояния ===
void set_state(t_philosopher *philo, t_state new_state)
{
    philo->state = new_state;
    if (new_state == THINKING)
        safe_print(philo, "is THINKING");
    else if (new_state == HUNGRY)
        safe_print(philo, "is HUNGRY");
    else if (new_state == EATING)
        safe_print(philo, "is EATING");
}

// === 7. Взять вилки с защитой от deadlock ===
void take_forks(t_philosopher *philo)
{
    if (philo->id % 2 == 0)
    {
        // Чётные (2,4): сначала левая, потом правая
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        safe_print(philo, "took left fork");

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        safe_print(philo, "took right fork");
    }
    else
    {
        // Нечётные (1,3,5): сначала правая, потом левая
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        safe_print(philo, "took right fork");

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        safe_print(philo, "took left fork");
    }
}

// === 8. Положить вилки ===
void put_forks(t_philosopher *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    philo->flags = PHILO_NONE;
    safe_print(philo, "put forks");
}

// === 9. Процесс еды ===
void eat(t_philosopher *philo)
{
    set_state(philo, EATING);
    usleep(500000); // 0.5 секунды
    philo->meals_eaten++;
}

// === 10. Процесс размышления ===
void think(t_philosopher *philo)
{
    set_state(philo, THINKING);
    usleep(300000); // 0.3 секунды
}

// === 11. Основной цикл философа ===
void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    while (philo->meals_eaten < philo->max_meals && g_table->running)
    {
        set_state(philo, HUNGRY);
        take_forks(philo);
        eat(philo);
        put_forks(philo);
        think(philo);
    }
    return NULL;
}

// === 12. Инициализация стола ===
int init_table(int num_philosophers, int max_meals)
{
    int i;

    g_table = (t_table *)malloc(sizeof(t_table));
    if (!g_table)
        return (0);
    g_table->num_philosophers = num_philosophers;
    g_table->running = 1;
    g_table->philos = (t_philosopher *)malloc(sizeof(t_philosopher) * num_philosophers);
    g_table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philosophers);
    pthread_mutex_init(&g_table->print_mutex, NULL);
    if (!g_table->philos || !g_table->forks)
        return (0);
    for (i = 0; i < num_philosophers; i++)
        pthread_mutex_init(&g_table->forks[i], NULL);
    for (i = 0; i < num_philosophers; i++)
    {
        g_table->philos[i].id = i;
        g_table->philos[i].state = THINKING;
        g_table->philos[i].flags = PHILO_NONE;
        g_table->philos[i].left_fork = &g_table->forks[i];
        g_table->philos[i].right_fork = &g_table->forks[(i + 1) % num_philosophers];
        g_table->philos[i].meals_eaten = 0;
        g_table->philos[i].max_meals = max_meals;
    }
    return (1);
}

// === 13. Запуск потоков ===
void start_dinner(void)
{
    int i;

    for (i = 0; i < g_table->num_philosophers; i++)
        pthread_create(&g_table->philos[i].thread, NULL, philosopher_routine, &g_table->philos[i]);
    for (i = 0; i < g_table->num_philosophers; i++)
        pthread_join(g_table->philos[i].thread, NULL);
}

// === 14. Очистка ресурсов ===
void cleanup_table(void)
{
    int i;

    for (i = 0; i < g_table->num_philosophers; i++)
        pthread_mutex_destroy(&g_table->forks[i]);
    pthread_mutex_destroy(&g_table->print_mutex);
    free(g_table->philos);
    free(g_table->forks);
    free(g_table);
    g_table = NULL;
}

// === 15. main ===
int main(void)
{
    int num_philosophers = 5;
    int max_meals = 3;  // каждый философ поест 3 раза, потом программа завершится

    printf("=== Dining Philosophers ===\n");
    printf("Each philosopher will eat %d times\n\n", max_meals);
    
    if (!init_table(num_philosophers, max_meals))
    {
        printf("Error: initialization failed\n");
        return (1);
    }
    start_dinner();
    cleanup_table();
    
    printf("\n=== All philosophers have finished eating ===\n");
    return (0);
}