/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:21:42 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/24 00:24:59 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

// message philo
# define FORK_R SYELLOW"has taken a fork (1/2)"NONE
# define FORK_L FYELLOW"has taken a fork (Ready!)"NONE
# define EAT FGREEN"is eating"NONE
# define SLEEP FCYAN"is sleeping"NONE
# define THINK PINK"is thinking"NONE
# define DIE FRED"died"NONE

// fork
# define TAKE 0
# define DROP 1

# define TRUE 1
# define FALSE 0
// error message
# define ARG 1
# define PHILO_MALLOC 2
# define FORK_MALLOC 3
# define THREAD_CREATE 4

typedef struct s_data
{
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				n_meal;
	long			t_start;
	int				philo_died;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int					name;
	pthread_t			t;
	long				last_meal;
	int					n_eated;
	int					left;
	int					right;
	t_data				*data;
}	t_philo;

typedef struct s_doctor
{
	int				id;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	t_data			data;
}	t_doctor;

int		ft_perror(int code);
void	get_input(t_data *data, int ac, char **av);
void	*ft_routine(void *arg);
void	init_philo(t_doctor *doctor);
void	create_thread(t_doctor *doctor, void *ft_routine);
long	current_time(void);
void	action_print(t_philo *philo, char *code);