#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));	
}

void	ft_alloc(t_doctor *doctor)
{
	doctor->philo = malloc(sizeof(t_philo) * doctor->data.n_philo);
	if (!doctor->philo)
		ft_perror("philo malloc failed\n");
	doctor->fork = malloc(sizeof(pthread_mutex_t) * doctor->data.n_philo);
	if (!doctor->fork)
		ft_perror("fork malloc failed\n");
}

void	routine_set(t_doctor *doctor)
{
	int	i;

	i = -1;
	ft_alloc(doctor)
	while (++i < doctor->data.n_philo)
	{
		doctor->philo[i].name = i + 1;
		doctor->philo[i].n_eated = 0;
		doctor->philo[i].left = i;
		doctor->philo[i].right = (i + 1) % doctor->data.n_philo;
		doctor->philo[i].data = &doctor->data;
		pthread_mutex_init(&doctor->fork[i], NULL);
	}
}

void	philo_create(t_doctor *doctor, void *ft_routine)
{
    int			i;

    i = 0;
	//printf("\n         ");
	printf("\n\t ");
	printf(BGWHITE" Time "NONE);
	printf("\t\t");
	printf(BGWHITE" Philo \n\n"NONE);
	//printf("      -----------------------------------------\n"NONE);
	doctor->data.t_start = current_time();
	while (i < doctor->data.n_philo)
		{
			doctor->id = i;
			if (pthread_create(&doctor->philo[i++].t, NULL, ft_routine, doctor))
			{
				printf("thread create fail\n");
				exit(1);
			}
			usleep (50);
		}
    i = -1;
	while (++i < doctor->data.n_philo)
		pthread_join(doctor->philo[i].t, NULL);
}