#ifndef THREE_H
# define THREE_H

# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>

# ifndef USE
#  define USE 1
# endif

# ifndef NOT_USE
#  define NOT_USE 0
# endif

# ifndef NO_LIMIT
#  define NO_LIMIT -1
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef DEAD
#  define DEAD 1
# endif

# ifndef ALIVE
#  define ALIVE 0
# endif

# ifndef SLEEPING
#  define SLEEPING 0
# endif

# ifndef EATING
#  define EATING 1
# endif

# ifndef FORKING
#  define FORKING 2
# endif

# ifndef THINKING
#  define THINKING 3
# endif

# ifndef DYING
#  define DYING 4
# endif

# ifndef NOTHING
#  define NOTHING 5
# endif

# ifndef FULL
#  define FULL 6
# endif

typedef struct timeval	t_timeval;
typedef int				t_bool;
typedef int				t_status;
typedef struct			s_philo
{
	pid_t				pid;
	int					number;
	int					ate_count;
	t_timeval			time_last_ate;
	t_status			status;
}						t_philo;

typedef struct			s_setup
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_must_eat;
	t_philo				*philo;
	t_timeval			time_start_experiment;
	sem_t				*fork;
	sem_t				*print_sem;
	sem_t				*dead_sem;
}						t_setup;

/*
** Src is : ../src/do.c
*/
int						do_sleep(t_philo *philo);
int						do_taking_fork(t_philo *philo);
int						do_eat(t_philo *philo);
t_bool					eat_enough(t_philo *philo);
int						do_think(t_philo *philo);

/*
** Src is : ../src/error.c
*/
void					error_arguments();
int						error_unexpected(void);

/*
** Src is : ../src/experiment.c
*/
int						start_experiment(t_setup *setting);
int						start_experiment(t_setup *setting);
void					philo_do_his_job(t_philo *philo);
void					*am_i_dead(void *philo_data);

/*
** Src is : ../src/parse.c
*/
void					parse_arguments(t_setup *setup, int ac, char *av[]);

/*
** Src is : ../src/prepare_experiment.c
*/
void					prepare_experiment(t_setup *setup);

/*
** Src is : ../src/print_current_job.c
*/
void					print_take_fork(t_philo *philo);
void					print_is_eating(t_philo *philo);
void					print_is_sleeping(t_philo *philo);
void					print_is_thinking(t_philo *philo);
void					print_died(t_philo *philo);

/*
** Src is : ../src/print_status.c
*/
void					print_status(t_philo *philo);

/*
** Src is : ../src/test.c
*/
void					print_setup(t_setup *setting);
void					print_timeval(t_timeval time, const char *s);
void					minus_time_test(void);

/*
** Src is : ../src/time.c
*/
void					sleep_for_ms(int millisecond);
long					minus_time(t_timeval *end, t_timeval *begin);

/*
** Src is : ../src/utils.c
*/
int						ft_atoi(const char *str);
void					init_semaphore(t_setup *setting);
sem_t					*init_fork(int number_of_fork);
sem_t					*init_print_sem(void);
sem_t					*init_dead_sem(void);
sem_t					*init_end_eating_sem(int number_of_must_eat);
void					destroy_fork(pthread_mutex_t *fork, int number_of_fork);
void					init_philo(t_philo *philo, int number, t_setup *setting);

#endif
