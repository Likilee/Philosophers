/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_job.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:04 by kilee             #+#    #+#             */
/*   Updated: 2021/04/08 13:59:07 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void		print_take_fork(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
	printf("%ld %d has taken a fork \n", time_ms, philo->number);
}

void		print_is_eating(t_philo *philo)
{
	t_timeval	now;
	long		time_ms;

	gettimeofday(&now, NULL);
	time_ms = minus_time(&now, &philo->setting->time_start_experiment);
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
