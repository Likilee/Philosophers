/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:16 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 14:43:08 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONE_H
# define ONE_H

# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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
typedef struct			s_setting
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	t_timeval			time_start_experiment;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print_mutex;
	t_bool				someone_dead;
}						t_setting;

typedef struct			s_philo
{
	int					number;
	int					ate_count;
	int					left_fork;
	int					right_fork;
	t_timeval			time_last_ate;
	t_setting			*setting;
	t_status			status;
}						t_philo;

/*
** Src is : ../src/do.c
*/
pthread_mutex_t			*init_fork(int number_of_fork);
void					destroy_fork(pthread_mutex_t *fork, int number_of_fork);
void					init_philo(t_philo *philo, int number,
									t_setting *setting);
int						do_sleep(t_philo *philo);
int						do_taking_fork(t_philo *philo);
t_bool					eat_enough(t_philo *philo);
int						do_eat(t_philo *philo);
int						do_think(t_philo *philo);
void					*am_i_dead(void *philo_data);
void					*philo_do_his_job(void *philo_data);
int						start_experiment(t_setting *setting);

/*
** Src is : ../src/error.c
*/
int						error_arg_count(int	ac);
int						error_arg_value(void);
int						error_unexpected(void);
void					*free_setting_and_return_null(t_setting	*setting);

/*
** Src is : ../src/parse.c
*/
t_setting				*parse_argv(int ac, char *av[]);

/*
** Src is : ../src/print.c
*/
void					print_status(t_philo *philo);
void					print_take_fork(t_philo *philo);
void					print_is_eating(t_philo *philo);
void					print_is_sleeping(t_philo *philo);
void					print_is_thinking(t_philo *philo);
void					print_died(t_philo *philo);
void					print_timeval(t_timeval time, const char *s);

/*
** Src is : ../src/test.c
*/
void					print_setting(t_setting *setting);
void					minus_time_test();

/*
** Src is : ../src/time.c
*/
void					sleep_for_ms(int millisecond);
long					minus_time(t_timeval *end, t_timeval *begin);

/*
** Src is : ../src/utils.c
*/
int						ft_atoi(const char *str);

#endif
