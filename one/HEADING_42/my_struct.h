/*
** MY_STRUCT_H : 헤더에 추가할 구조체 작성.
** -Start- 줄과 -End- 줄 사이에 사용할 구조체 들을 작성해주세요!
** 여러 구조체를 사용한다면 줄바꿈 후 계속 작성하면 됩니다!
*/

/* -Start-Write your structs just right down */

typedef struct timeval	t_timeval;

typedef int	t_bool;

typedef int	t_status;

typedef struct	s_setting
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	t_timeval	time_start_experiment;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	t_bool	someone_dead;
}			t_setting;

typedef struct	s_philo
{
	int			number;
	int			ate_count;
	t_bool		ate_enough;
	int			left_fork;
	int			right_fork;
	t_timeval	time_last_ate;
	t_setting	*setting;
	t_status	status;
}	t_philo;

/* -End- finish!# */
