#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

void	break_mutex(t_doctor *doctor)
{
	int	i;

	i = 0;
	while (i < doctor->data.n_philo)
	{
		pthread_mutex_destroy(&doctor->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&doctor->data.print);
}

void	philo_clear(t_doctor *doctor)
{
	break_mutex(doctor);
	free(doctor->fork);
	free(doctor->philo);
}

int main(int ac, char **av)
{
	t_doctor	doctor;

	if (ac != 5 && ac != 6)
		ft_perror(ARG);
	get_input(&doctor.data, ac, av);
	init_philo(&doctor);
	create_thread(&doctor, &ft_routine);
	philo_clear(&doctor);
	return (0);
}