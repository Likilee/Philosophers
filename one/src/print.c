#include "one.h"

/*
** timestamp_in_ms X has taken a fork
** timestamp_in_ms X is eating
** timestamp_in_ms X is sleeping
** timestamp_in_ms X is thinking
** timestamp_in_ms X died
*/

void		print_take_fork(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(now, philo->setting->time_start_experiment);
	printf("%ld %d has taken a fork\n", time_ms, philo->number);
}

void		print_is_eating(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(now, philo->setting->time_start_experiment);
	printf("%ld %d is eating\n", time_ms, philo->number);
}

void		print_is_sleeping(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(now, philo->setting->time_start_experiment);
	printf("%ld %d is sleeping\n", time_ms, philo->number);
}

void		print_is_thinking(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(now, philo->setting->time_start_experiment);
	printf("%ld %d is thinking\n", time_ms, philo->number);
}

void		print_died(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(now, philo->setting->time_start_experiment);
	printf("%ld %d died\n", time_ms, philo->number);
}
