/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_job.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:04 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 16:02:36 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void		print_take_fork(t_philo *philo, long now)
{
	long		time;

	time = now - philo->time_start;
	printf("%ld %d has taken a fork \n", time, philo->number);
	// write(1, "fork\n", 5);
}

void		print_is_eating(t_philo *philo, long now)
{
	long		time;

	time = now - philo->time_start;
	printf("%ld %d is eating\n", time, philo->number);
	// write(1, "eat\n", 4);

}

void		print_is_sleeping(t_philo *philo, long now)
{
	long		time;

	time = now - philo->time_start;
	printf("%ld %d is sleeping\n", time, philo->number);
	// write(1, "sleep\n", 6);
}

void		print_is_thinking(t_philo *philo, long now)
{
	long		time;

	time = now - philo->time_start;
	printf("%ld %d is thinking\n", time, philo->number);
	// write(1, "think\n", 6);
}

void		print_died(t_philo *philo, long now)
{
	long		time;

	time = now - philo->time_start;
	printf("%ld %d died\n", time, philo->number);
	// write(1, "died\n", 5);
}
