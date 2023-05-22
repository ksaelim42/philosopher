#include "philo.h"
#include "stdio.h"
#include <stdlib.h>



static int	use_fork(t_philo *philo, pthread_mutex_t *fork, int mode)
{
	if (mode == 0)
	{
    	if (pthread_mutex_lock(&fork[philo->right]))
			return (EXIT_FAILURE);
		action_print(philo, FORK_R);
    	if (pthread_mutex_lock(&fork[philo->left]))
			return (EXIT_FAILURE);
		action_print(philo, FORK_L);
	}
	else if (mode == 1)
	{
		pthread_mutex_unlock(&fork[philo->right]);
			return (EXIT_FAILURE);
		pthread_mutex_unlock(&fork[philo->left]);
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	philo_eat(t_philo *philo, pthread_mutex_t *fork)
{
	if (use_fork(philo, fork, TAKE))
		return(use_fork(philo, fork, DROP));
	action_print(philo, EAT);
	usleep(100);
	use_fork(philo, fork, DROP);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	action_print(philo, THINK);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	action_print(philo, SLEEP);
	usleep(200);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_doctor	*doctor;

	doctor = (t_doctor *)arg;
	while (doctor->philo->n_eated < doctor->data.n_meal)
	{
		if (philo_eat(&doctor->philo[doctor->id], doctor->fork))
			return (NULL);
		if (philo_sleep(&doctor->philo[doctor->id]))
			return (NULL);
		if (philo_think(&doctor->philo[doctor->id]))
			return (NULL);
	}
	return (NULL);
}