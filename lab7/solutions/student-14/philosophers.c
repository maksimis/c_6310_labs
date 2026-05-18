#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_CYCLES 3

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
    pthread_mutex_t *print_mutex;
}   t_philosopher;



void    print_action(t_philosopher *philo, const char *msg)
{
    pthread_mutex_lock(philo->print_mutex);
    printf("Philosopher %d %s\n", philo->id, msg);
    pthread_mutex_unlock(philo->print_mutex);
}


void    think(t_philosopher *philo)
{
    philo->state = THINKING;
    print_action(philo, "is THINKING");
    usleep(100000);
}

void    eat(t_philosopher *philo)
{
    philo->state = EATING;
    print_action(philo, "is EATING");
    usleep(100000);
}

void    take_forks(t_philosopher *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        print_action(philo, "took left fork");

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        print_action(philo, "took right fork");
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        print_action(philo, "took right fork");

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        print_action(philo, "took left fork");
    }
}

void    put_forks(t_philosopher *philo)
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

    print_action(philo, "put forks");
}

void    *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    for (int i = 0; i < NUM_CYCLES; i++)
    {
        think(philo);

        philo->state = HUNGRY;
        print_action(philo, "is HUNGRY");

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
    t_philosopher philosophers[NUM_PHILOSOPHERS];

    pthread_mutex_init(&print_mutex, NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosophers[i].id = i + 1;
        philosophers[i].state = THINKING;
        philosophers[i].flags = PHILO_NONE;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];
        philosophers[i].print_mutex = &print_mutex;
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_create(
            &philosophers[i].thread,
            NULL,
            philosopher_routine,
            &philosophers[i]
        );
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_join(philosophers[i].thread, NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_mutex_destroy(&forks[i]);

    pthread_mutex_destroy(&print_mutex);

    return (0);
}