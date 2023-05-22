#include "philo.h"

static int ft_atoi(char *s)
{
    int num;

    if (!s || *s == '\0')
        ft_perror(EXIT_FAILURE);
    num = 0;
    while (*s >= '0' && *s <= '9')
        num = (num * 10) + (*s++ - '0');
    if (*s != '\0')
        ft_perror(EXIT_FAILURE);
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
		data->n_meal = 1;
}