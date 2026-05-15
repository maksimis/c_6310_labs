#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

# define PHILO_COUNT 5
# define CYCLES 3
# define THINK_TIME_US 200000
# define EAT_TIME_US 150000

typedef enum e_state
{
	THINKING,
	HUNGRY,
	EATING
}   t_state;

typedef enum e_philo_flags
{
	PHILO_NONE = 0,
	PHILO_HAS_LEFT = 1 << 0,
	PHILO_HAS_RIGHT = 1 << 1
}   t_philo_flags;

typedef struct s_shared
{
	pthread_mutex_t	print_mutex;
}   t_shared;

typedef struct s_philosopher
{
	int				id;
	t_state			state;
	t_philo_flags	flags;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_shared		*shared;
	int				cycles;
}   t_philosopher;

void	*philosopher_routine(void *arg);
void	think(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	take_forks(t_philosopher *philo);
void	put_forks(t_philosopher *philo);
void	print_action(t_philosopher *philo, const char *message);

#endif