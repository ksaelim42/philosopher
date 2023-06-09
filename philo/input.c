/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:50 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/24 00:27:43 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *s)
{
	int	num;

	if (!s || *s == '\0')
		ft_perror(ARG);
	num = 0;
	while (*s >= '0' && *s <= '9')
		num = (num * 10) + (*s++ - '0');
	if (*s != '\0')
		ft_perror(ARG);
	return (num);
}

void	get_input(t_data *data, int ac, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meal = ft_atoi(av[5]);
	else
		data->n_meal = -1;
	data->philo_died = FALSE;
}
