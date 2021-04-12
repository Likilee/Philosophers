/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:49:11 by kilee             #+#    #+#             */
/*   Updated: 2021/04/12 10:49:12 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_H
# define THREE_H

# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

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
	struct s_setup		*setup;
	long				time_start;
	long				time_last_ate;
	long				time_now;
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
}						t_setup;

/*
** Src is : ../src/clear.c
*/
void					clear(t_setup *setup);

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
void					error_arguments(void);
int						error_unexpected(void);

/*
** Src is : ../src/experiment.c
*/
void					run_experiment(t_setup *setup);
void					philo_do_his_job(t_philo *philo);
void					*am_i_dead(void *philo_data);

/*
** Src is : ../src/is_valid_arguments.c
*/
t_bool					is_valid_arguments(int ac, char *av[]);

/*
** Src is : ../src/manage_process.c
*/
void					manage_process(t_setup *setup);
t_bool					is_full_philo(int status);
t_bool					is_dead_philo(int status);
void					finish_experiment(t_setup *setup);

/*
** Src is : ../src/parse.c
*/
void					parse_arguments(t_setup *setup, int ac, char *av[]);

/*
** Src is : ../src/prepare_experiment.c
*/
void					prepare_experiment(t_setup *setup);
void					init_philosophers(t_setup *setup);
void					init_semaphore(t_setup *setup);

/*
** Src is : ../src/print_current_job.c
*/
void					print_take_fork(t_philo *philo, long now);
void					print_is_eating(t_philo *philo, long now);
void					print_is_sleeping(t_philo *philo, long now);
void					print_is_thinking(t_philo *philo, long now);
void					print_died(t_philo *philo, long now);

/*
** Src is : ../src/print_status.c
*/
void					print_status(t_philo *philo, long now);

/*
** Src is : ../src/test.c
*/
void					print_setup(t_setup *setting);
void					print_timeval(t_timeval time, const char *s);

/*
** Src is : ../src/time.c
*/
void					sleep_for_ms(int millisecond);
long					get_m_second(void);

/*
** Src is : ../src/utils.c
*/
int						ft_atoi(const char *str);

#endif
