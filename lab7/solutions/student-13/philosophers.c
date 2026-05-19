#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define PHILO_COUNT 5
#define EAT_COUNT 3

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
	int				id;
	t_state			state;
	t_philo_flags	flags;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosopher;

void	print_state(t_philosopher *philo, const char *message)
{
	printf("Philosopher %d %s\n", philo->id, message);
}

void	think(t_philosopher *philo)
{
	philo->state = THINKING;
	print_state(philo, "is THINKING");
	usleep(100000);
}

void	take_forks(t_philosopher *philo)
{
	philo->state = HUNGRY;
	print_state(philo, "is HUNGRY");
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_state(philo, "took left fork");
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_state(philo, "took right fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_state(philo, "took right fork");
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_state(philo, "took left fork");
	}
}

void	eat(t_philosopher *philo)
{
	philo->state = EATING;
	print_state(philo, "is EATING");
	usleep(100000);
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
	print_state(philo, "put forks");
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				i;

	philo = (t_philosopher *)arg;
	i = 0;
	while (i < EAT_COUNT)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		i++;
	}
	return (NULL);
}

void	init_forks(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_philosopher *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		philos[i].flags = PHILO_NONE;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % PHILO_COUNT];
		i++;
	}
}

void	destroy_forks(pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	main(void)
{
	pthread_mutex_t	forks[PHILO_COUNT];
	t_philosopher	philos[PHILO_COUNT];
	int				i;

	init_forks(forks);
	init_philosophers(philos, forks);
	i = 0;
	while (i < PHILO_COUNT)
	{
		pthread_create(&philos[i].thread, NULL,
			philosopher_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < PHILO_COUNT)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	destroy_forks(forks);
	return (0);
}