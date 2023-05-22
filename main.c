#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	check_format(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (1);
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if (check_format(av))
		return (1);
	return (0);
}

	if (ac != 5 && ac != 6)
	{
		printf(FRED"Error:	"NONE);
		printf(FWHITE"Invalid argument(s)!\n"NONE);
		printf(FYELLOW"Usage:"NONE);
		printf(FWHITE"	./philo [num of philo] [time to die] [time to eat] [time to sleep] {option: num of meal}\n"NONE);
		exit(0);
	}
}

int	ft_init(t_doctor *doctor, int ac, char **av)
{
	if (get_input(&doctor.data, ac, av))
		return (1);
}

int main(int ac, char **av)
{
	t_doctor	doctor;

	if (check_arg(ac, av))
		return (ft_perror(ARG), 1);
	if (ft_init(&doctor, ac, av))
		return (1);
	get_input(&doctor.data, ac, av);
	routine_set(&doctor);
	philo_create(&doctor, &ft_routine);
	//philo_clear();i
	return (0);
}