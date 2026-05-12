#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5
#define NUM_MEALS 3

typedef enum e_state
{
    THINKING,
    HUNGRY,
    EATING
} t_state;

typedef enum e_philo_flags
{
    PHILO_NONE = 0,
    PHILO_HAS_LEFT  = 1 << 0,
    PHILO_HAS_RIGHT = 1 << 1
}   t_philo_flags;

typedef struct s_philosopher
{
    int id; 
    t_state state;
    t_philo_flags flags;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *print_mutex;
} t_philosopher;

//безопасный вывод
static void print_action(t_philosopher *philo, const char *action)
{
    pthread_mutex_lock(philo->print_mutex);
    printf("Philosopher %d %s\n", philo->id, action);
    pthread_mutex_unlock(philo->print_mutex);
}

//перевод в состояние HUNGRY и захват двух вилок
static void take_forks(t_philosopher *philo)
{
    philo->state = HUNGRY;
    print_action(philo, "is HUNGRY");

    if (philo->id % 2 == 0)
    {
        /* Чётный философ: сначала правая вилка, потом левая */
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        print_action(philo, "took right fork");

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        print_action(philo, "took left fork");
    }
    else
    {
        /* Нечётный философ: сначала левая вилка, потом правая */
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        print_action(philo, "took left fork");

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        print_action(philo, "took right fork");
    }
}

// перевод философа в состояние EATING и имитация приёма пищи
static void eat(t_philosopher *philo)
{
    philo->state = EATING;
    print_action(philo, "is EATING");
    usleep(200000);
}

// освобождение обеих вилок и сброс флагов.
static void put_forks(t_philosopher *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    philo->flags = PHILO_NONE;
    print_action(philo, "put forks");
}

// перевод философа в состояние THINKING и имитация размышления.
static void think(t_philosopher *philo)
{
    philo->state = THINKING;
    print_action(philo, "is THINKING");
    usleep(100000);
}

//точка входа потока каждого философа.
static void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    int meal;

    for (meal = 0; meal < NUM_MEALS; meal++)
    {
        think(philo);
        take_forks(philo);
        eat(philo);
        put_forks(philo);
    }
    return (NULL);
}

int main(void)
{
    pthread_mutex_t forks[NUM_PHILOSOPHERS]; 
    pthread_mutex_t print_mutex; 
    t_philosopher philos[NUM_PHILOSOPHERS]; // массив из 5 структур философов
    int i;

    pthread_mutex_init(&print_mutex, NULL);// Инициализация мьютекса для вывода
    for (i = 0; i < NUM_PHILOSOPHERS; i++)// Инициализация 5 мьютексов для вилок
        pthread_mutex_init(&forks[i], NULL);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) //инициализация структур философов
    {
        philos[i].id = i + 1;
        philos[i].state = THINKING;
        philos[i].flags = PHILO_NONE;
        philos[i].left_fork = &forks[i];
        philos[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];
        philos[i].print_mutex = &print_mutex;
    }

    //запускаются 5 потоков: по одному на каждого философа
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);

    // ожидание заверешения всех потоков
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_join(philos[i].thread, NULL);

    //уничтожение всех мьютексов
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_mutex_destroy(&forks[i]);
    pthread_mutex_destroy(&print_mutex);

    return (0);
}
