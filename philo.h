#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define FORK_R SYELLOW"has taken a fork (1/2)"NONE
#define FORK_L FYELLOW"has taken a fork (Ready!)"NONE
#define EAT FGREEN"is eating"NONE
#define SLEEP FCYAN"is sleeping"NONE
#define THINK PINK"is thinking"NONE
#define DIE FRED"died"NONE
#define TAKE 0
#define DROP 1

typedef struct s_data
{
	int		n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		n_meal;
	long	t_start;
}   t_data;

typedef struct s_philo
{
	int					name;
	pthread_t			t;
	int					last_meal;
	int					n_eated;
	int					left;
	int					right;
	t_data				*data;
}   t_philo;

typedef struct s_doctor
{
	int				id;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	t_data			data;
}   t_doctor;

void	get_input(t_data *data, int ac, char **av);
void	*ft_routine(void *arg);
void	routine_set(t_doctor *doctor);
void	philo_create(t_doctor *doctor, void *ft_routine);
long	current_time(void);
void	action_print(t_philo *philo, char *code);