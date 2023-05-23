/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:23 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/24 00:20:31 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include "color.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	alloc_philo_and_fork(t_doctor *doctor)
{
	doctor->philo = malloc(sizeof(t_philo) * doctor->data.n_philo);
	if (!doctor->philo)
		ft_perror(PHILO_MALLOC);
	doctor->fork = malloc(sizeof(pthread_mutex_t) * doctor->data.n_philo);
	if (!doctor->fork)
		ft_perror(FORK_MALLOC);
}

void	init_philo(t_doctor *doctor)
{
	int	i;

	i = -1;
	alloc_philo_and_fork(doctor);
	while (++i < doctor->data.n_philo)
	{
		doctor->philo[i].name = i + 1;
		doctor->philo[i].n_eated = 0;
		doctor->philo[i].left = i;
		doctor->philo[i].right = (i + 1) % doctor->data.n_philo;
		doctor->philo[i].data = &doctor->data;
		pthread_mutex_init(&doctor->fork[i], NULL);
	}
	pthread_mutex_init(&doctor->data.print, NULL);
}

void	print_label(void)
{
	printf("\n\t ");
	printf(BGWHITE" Time "NONE);
	printf("\t\t");
	printf(BGWHITE" Philo \n\n"NONE);
}

void	create_thread(t_doctor *doctor, void *ft_routine)
{
	int	i;

	i = 0;
	print_label();
	doctor->data.t_start = current_time();
	while (i < doctor->data.n_philo)
	{
		doctor->id = i;
		if (pthread_create(&doctor->philo[i++].t, NULL, ft_routine, doctor))
			ft_perror(THREAD_CREATE);
		usleep (50);
	}
	i = -1;
	while (++i < doctor->data.n_philo)
		pthread_join(doctor->philo[i].t, NULL);
}
