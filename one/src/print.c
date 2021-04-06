#include "one.h"

/*
** timestamp_in_ms X has taken a fork
** timestamp_in_ms X is eating
** timestamp_in_ms X is sleeping
** timestamp_in_ms X is thinking
** timestamp_in_ms X died
*/

void		print_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->setting->print_mutex);
	// printf("hihi");
	if (philo->setting->someone_dead == FALSE)
	{
		if (philo->status == FORKING)
			print_take_fork(philo);
		else if (philo->status == EATING)
			print_is_eating(philo);
		else if (philo->status == SLEEPING)
			print_is_sleeping(philo);
		else if (philo->status == THINKING)
			print_is_thinking(philo);
		else if (philo->status == DYING)
		{
			print_died(philo);
			philo->setting->someone_dead = TRUE;
		}
	}
	pthread_mutex_unlock(&philo->setting->print_mutex);
}

void		print_take_fork(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	// printf("%ld %d has taken a fork ", time_ms, philo->number);
	// printf("lfork_index : %d\n", philo->left_fork);
	printf("%ld %d has taken %dth fork \n", time_ms, philo->number, philo->left_fork);
}

void		print_is_eating(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	printf("%ld %d has taken %dth fork \n", time_ms, philo->number, philo->right_fork);
	printf("%ld %d is eating\n", time_ms, philo->number);
}

void		print_is_sleeping(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	printf("%ld %d is sleeping\n", time_ms, philo->number);
}

void		print_is_thinking(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	printf("%ld %d is thinking\n", time_ms, philo->number);
}

void		print_died(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	printf("%ld %d died\n", time_ms, philo->number);
}

void		print_timeval(t_timeval time, const char *s)
{
	long	millisecond;

	millisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%s :", s);
	printf(" %ld ms\n", millisecond);
}

