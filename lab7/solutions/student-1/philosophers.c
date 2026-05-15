#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define EAT_CYCLES 3

typedef enum e_state
{
    THINKING,
    HUNGRY,
    EATING
}   t_state;

typedef enum e_philo_flags
{
    PHILO_NONE      = 0,
    PHILO_HAS_LEFT  = 1 << 0,
    PHILO_HAS_RIGHT = 1 << 1
}   t_philo_flags;

typedef struct s_philosopher
{
    int             id;
    t_state         state;
    t_philo_flags   flags;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philosopher;

void think(t_philosopher *philo)
{
    philo->state = THINKING;
    printf("Philosopher %d is THINKING\n", philo->id);
    usleep(200000);
}

void take_forks(t_philosopher *philo)
{
    /*
    Защита от deadlock:
    чётные философы:
        left -> right
    нечётные:
        right -> left
    */

    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        printf("Philosopher %d took LEFT fork\n", philo->id);

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took RIGHT fork\n", philo->id);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took RIGHT fork\n", philo->id);

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        printf("Philosopher %d took LEFT fork\n", philo->id);
    }
}

void eat(t_philosopher *philo)
{
    philo->state = EATING;
    printf("Philosopher %d is EATING\n", philo->id);
    usleep(200000);
}

void put_forks(t_philosopher *philo)
{
    if (philo->flags & PHILO_HAS_LEFT)
    {
        pthread_mutex_unlock(philo->left_fork);
        philo->flags &= ~PHILO_HAS_LEFT;
    }

    if (philo->flags & PHILO_HAS_RIGHT)
    {
        pthread_mutex_unlock(philo->right_fork);
        philo->flags &= ~PHILO_HAS_RIGHT;
    }

    printf("Philosopher %d put forks\n", philo->id);
}

void *philosopher_routine(void *arg)
{
    t_philosopher *philo;
    int             i;

    philo = (t_philosopher *)arg;
    i = 0;

    while (i < EAT_CYCLES)
    {
        think(philo);

        philo->state = HUNGRY;
        printf("Philosopher %d is HUNGRY\n", philo->id);

        take_forks(philo);
        eat(philo);
        put_forks(philo);

        i++;
    }

    return (NULL);
}

int main(void)
{
    pthread_mutex_t forks[NUM_PHILOSOPHERS];
    t_philosopher philosophers[NUM_PHILOSOPHERS];
    int i;

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        philosophers[i].id = i + 1;
        philosophers[i].state = THINKING;
        philosophers[i].flags = PHILO_NONE;

        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];

        pthread_create(
            &philosophers[i].thread,
            NULL,
            philosopher_routine,
            &philosophers[i]
        );

        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }

    return (0);
}