#include "philo.h"
#include <stdio.h>
#include "color.h"

int ft_perror(int arc)
{
    printf("exit_succes not use exit yet!\n");
    return (0);
}

void	action_print(t_philo *philo, char *code)
{
	printf(BWHITE"\t %ld "NONE, current_time() - philo->data->t_start);
	printf(FPURPLE"ms\t\t"NONE);
	printf("[%d]"NONE, philo->name);
	printf(" %s\n", code);
}
