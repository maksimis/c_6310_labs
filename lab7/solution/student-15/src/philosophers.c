#include "philosophers.h"

void	print_action(t_philosopher *philo, const char *message)
{
	pthread_mutex_lock(&philo->shared->print_mutex);
	printf("Philosopher %d %s\n", philo->id, message);
	pthread_mutex_unlock(&philo->shared->print_mutex);
}

void	think(t_philosopher *philo)
{
	philo->state = THINKING;
	print_action(philo, "is THINKING");
	usleep(THINK_TIME_US);
}

void	take_forks(t_philosopher *philo)
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

void	eat(t_philosopher *philo)
{
	philo->state = EATING;
	print_action(philo, "is EATING");
	usleep(EAT_TIME_US);
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

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				i;

	philo = (t_philosopher *)arg;
	i = 0;
	while (i < philo->cycles)
	{
		think(philo);
		philo->state = HUNGRY;
		print_action(philo, "is HUNGRY");
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		i++;
	}
	return (NULL);
}

static int	init_mutexes(pthread_mutex_t forks[PHILO_COUNT], t_shared *shared)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&shared->print_mutex, NULL) != 0)
		return (1);
	return (0);
}

static void	init_philosophers(t_philosopher philos[PHILO_COUNT],
		pthread_mutex_t forks[PHILO_COUNT], t_shared *shared)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		philos[i].flags = PHILO_NONE;
		philos[i].thread = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % PHILO_COUNT];
		philos[i].shared = shared;
		philos[i].cycles = CYCLES;
		i++;
	}
}

static int	create_threads(t_philosopher philos[PHILO_COUNT], int *created)
{
	int	i;

	i = 0;
	*created = 0;
	while (i < PHILO_COUNT)
	{
		if (pthread_create(&philos[i].thread, NULL,
				philosopher_routine, &philos[i]) != 0)
			return (1);
		(*created)++;
		i++;
	}
	return (0);
}

static void	join_threads(t_philosopher philos[PHILO_COUNT], int created)
{
	int	i;

	i = 0;
	while (i < created)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

static void	destroy_mutexes(pthread_mutex_t forks[PHILO_COUNT], t_shared *shared)
{
	int	i;

	i = 0;
	while (i < PHILO_COUNT)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&shared->print_mutex);
}

int	main(void)
{
	pthread_mutex_t	forks[PHILO_COUNT];
	t_philosopher	philos[PHILO_COUNT];
	t_shared		shared;
	int				created;

	if (init_mutexes(forks, &shared) != 0)
	{
		printf("Error: mutex init failed\n");
		return (1);
	}
	init_philosophers(philos, forks, &shared);
	if (create_threads(philos, &created) != 0)
	{
		printf("Error: thread creation failed\n");
		join_threads(philos, created);
		destroy_mutexes(forks, &shared);
		return (1);
	}
	join_threads(philos, created);
	destroy_mutexes(forks, &shared);
	return (0);
}