#include "philo.h"
#include "stdio.h"
#include "color.h"
#include <stdlib.h>

int	check_died(t_philo *philo)
{
	if (current_time() - philo->last_meal < philo->data->t_die)
		return (FALSE);
	philo->data->philo_died = 1;
	return (TRUE);
}

static int	use_fork(t_philo *philo, pthread_mutex_t *fork, int mode)
{
	if (mode == TAKE)
	{
    	if (pthread_mutex_lock(&fork[philo->right]))
			return (EXIT_FAILURE);
		action_print(philo, FORK_R);
    	if (pthread_mutex_lock(&fork[philo->left]))
			return (EXIT_FAILURE);
		action_print(philo, FORK_L);
	}
	else if (mode == DROP)
	{
		if (pthread_mutex_unlock(&fork[philo->right]))
			return (EXIT_FAILURE);
		if (pthread_mutex_unlock(&fork[philo->left]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	time_use(t_philo *philo, int time_use)
{
	long	start_time;

	start_time = current_time();
	while (!philo->data->philo_died && (current_time() - start_time < time_use))
		usleep(1);
	return (philo->data->philo_died);
	// 	return (TRUE);
	// return (FALSE);
}

static int	philo_eat(t_philo *philo, pthread_mutex_t *fork)
{
	// if (use_fork(philo, fork, TAKE))
		// return(use_fork(philo, fork, DROP));
	if (use_fork(philo, fork, TAKE))
		return (1);
	action_print(philo, EAT);
	philo->last_meal = current_time();
	if (time_use(philo, philo->data->t_eat))
	{
		printf("die between eat\n");
		return (1);
	}
	use_fork(philo, fork, DROP);
	philo->n_eated++;
	if (philo->n_eated == philo->data->n_meal)
		return (1);
	return (0);
}

static int	philo_sleep_and_think(t_philo *philo)
{
	action_print(philo, SLEEP);
	if (time_use(philo, philo->data->t_sleep))
		return (1);
	action_print(philo, THINK);
	return (0);
}

void	*ft_routine(void *arg)
{
	int			id;
	t_doctor	*doctor;

	doctor = (t_doctor *)arg;
	id = doctor->id;
	while (!doctor->data.philo_died && (doctor->philo[id].n_eated < doctor->data.n_meal || doctor->data.n_meal == -1))
	{
		// if (check_died(&doctor->philo[id]))
		// 	return (NULL);
		if (philo_eat(&doctor->philo[id], doctor->fork))
			break ;
		if (check_died(&doctor->philo[id]))
			break ;
		if (philo_sleep_and_think(&doctor->philo[id]))
			break ;
		if (check_died(&doctor->philo[id]))
			break ;
	}
	if (doctor->data.philo_died)
	{
		action_print(&doctor->philo[id], DIE);
	}
	return (NULL);
}