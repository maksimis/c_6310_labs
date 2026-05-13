#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_PHILOSOPHERS 5
#define NUM_ITERATIONS 3

typedef enum e_state
{
	THINKING,
	HUNGRY,
	EATING
}	t_state;

typedef enum e_philo_flags
{
	PHILO_NONE = 0,
	PHILO_HAS_LEFT = 1 << 0,
	PHILO_HAS_RIGHT = 1 << 1
}	t_philo_flags;

typedef struct s_philosopher
{
	int					id;
	t_state				state;
	t_philo_flags		flags;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					iterations;
}	t_philosopher;

const char	*state_to_string(t_state state)
{
	if (state == THINKING)
		return ("THINKING");
	if (state == HUNGRY)
		return ("HUNGRY");
	if (state == EATING)
		return ("EATING");
	return ("UNKNOWN");
}

void	print_action(t_philosopher *philo, const char *action)
{
	printf("Philosopher %d %s\n", philo->id, action);
	fflush(stdout);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_action(philo, "took left fork");
		
		usleep(100000);
		
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_action(philo, "took right fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_action(philo, "took right fork");
		
		usleep(100000);
		
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_action(philo, "took left fork");
	}
}

void	put_forks(t_philosopher *philo)
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

void	think(t_philosopher *philo)
{
	philo->state = THINKING;
	print_action(philo, "is THINKING");
	usleep(500000);
}

void	eat(t_philosopher *philo)
{
	philo->state = EATING;
	print_action(philo, "is EATING");
	usleep(500000);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo->iterations > 0)
	{
		think(philo);
		
		philo->state = HUNGRY;
		print_action(philo, "is HUNGRY");
		
		take_forks(philo);
		
		eat(philo);
		
		put_forks(philo);
		
		philo->iterations--;
	}
	return (NULL);
}

int	main(void)
{
	pthread_mutex_t	forks[NUM_PHILOSOPHERS];
	t_philosopher	philosophers[NUM_PHILOSOPHERS];
	int				i;

	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error: failed to init mutex %d\n", i);
			return (1);
		}
	}

	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		philosophers[i].id = i + 1;
		philosophers[i].state = THINKING;
		philosophers[i].flags = PHILO_NONE;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];
		philosophers[i].iterations = NUM_ITERATIONS;
	}

	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		if (pthread_create(&philosophers[i].thread, NULL, 
			philosopher_routine, &philosophers[i]) != 0)
		{
			printf("Error: failed to create thread %d\n", i);
			return (1);
		}
	}

	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		if (pthread_join(philosophers[i].thread, NULL) != 0)
		{
			printf("Error: failed to join thread %d\n", i);
			return (1);
		}
	}

	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
		{
			printf("Error: failed to destroy mutex %d\n", i);
			return (1);
		}
	}

	printf("All philosophers finished eating\n");
	return (0);
}
