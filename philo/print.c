/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:20:55 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/24 00:28:05 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int	ft_perror(int code)
{
	if (code == ARG)
	{
		printf(FRED"Error:	"NONE);
		printf(FWHITE"Invalid argument(s)!\n"NONE);
		printf(FYELLOW"Usage:"NONE);
		printf(FWHITE"	./philo [num of philo] [time to die] [time to eat] \
		[time to sleep] {option: num of meal}\n"NONE);
	}
	else if (code == PHILO_MALLOC)
		printf("FAIL TO MALLOC PHILO");
	else if (code == FORK_MALLOC)
		printf("FAIL TO MALLOC FORK");
	exit(EXIT_FAILURE);
}

void	action_print(t_philo *philo, char *code)
{
	pthread_mutex_lock(&philo->data->print);
	printf(BWHITE"\t %ld "NONE, current_time() - philo->data->t_start);
	printf(FPURPLE"ms\t\t"NONE);
	printf("[%d] %s\n", philo->name, code);
	pthread_mutex_unlock(&philo->data->print);
}
