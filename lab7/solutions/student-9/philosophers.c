#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define PHILO_COUNT 5
#define CYCLES 3

typedef enum e_state {
    THINKING,
    HUNGRY,
    EATING
} t_state;

typedef enum e_philo_flags {
    PHILO_NONE = 0,
    PHILO_HAS_LEFT = 1 << 0,
    PHILO_HAS_RIGHT = 1 << 1
} t_philo_flags;

typedef struct s_philosopher {
    int id;
    t_state state;
    t_philo_flags flags;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *print_mutex;
} t_philosopher;

typedef struct s_table {
    pthread_mutex_t forks[PHILO_COUNT];
    pthread_mutex_t print_mutex;
    t_philosopher philosophers[PHILO_COUNT];
} t_table;

static void safe_print(t_philosopher *philo, const char *msg) {
    pthread_mutex_lock(philo->print_mutex);
    printf("Philosopher %d %s\n", philo->id, msg);
    pthread_mutex_unlock(philo->print_mutex);
}

static void think(t_philosopher *philo) {
    philo->state = THINKING;
    safe_print(philo, "is THINKING");
    usleep(100000);
}

static void eat(t_philosopher *philo) {
    philo->state = EATING;
    safe_print(philo, "is EATING");
    usleep(100000);
}

static void take_forks(t_philosopher *philo) {
    philo->state = HUNGRY;
    safe_print(philo, "is HUNGRY");

    if (philo->id % 2 == 0) {
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        safe_print(philo, "took left fork");

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        safe_print(philo, "took right fork");
    } else {
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        safe_print(philo, "took right fork");

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        safe_print(philo, "took left fork");
    }
}

static void put_forks(t_philosopher *philo) {
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);

    philo->flags = PHILO_NONE;
    safe_print(philo, "put forks");
}

static void *philosopher_routine(void *arg) {
    t_philosopher *philo = (t_philosopher *)arg;

    for (int i = 0; i < CYCLES; i++) {
        think(philo);
        take_forks(philo);
        eat(philo);
        put_forks(philo);
    }
    return NULL;
}

int main(void) {
    t_table table;

    pthread_mutex_init(&table.print_mutex, NULL);

    for (int i = 0; i < PHILO_COUNT; i++) {
        pthread_mutex_init(&table.forks[i], NULL);
    }

    for (int i = 0; i < PHILO_COUNT; i++) {
        table.philosophers[i].id = i + 1;
        table.philosophers[i].state = THINKING;
        table.philosophers[i].flags = PHILO_NONE;
        table.philosophers[i].left_fork = &table.forks[i];
        table.philosophers[i].right_fork = &table.forks[(i + 1) % PHILO_COUNT];
        table.philosophers[i].print_mutex = &table.print_mutex;

        pthread_create(&table.philosophers[i].thread, NULL,
            philosopher_routine, &table.philosophers[i]);
    }

    for (int i = 0; i < PHILO_COUNT; i++) {
        pthread_join(table.philosophers[i].thread, NULL);
    }

    for (int i = 0; i < PHILO_COUNT; i++) {
        pthread_mutex_destroy(&table.forks[i]);
    }

    pthread_mutex_destroy(&table.print_mutex);

    return 0;
}