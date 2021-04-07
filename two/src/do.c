/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:43:41 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 14:49:00 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int				do_sleep(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	philo->status = SLEEPING;
	print_status(philo);
	sleep_for_ms(philo->setting->time_to_sleep);
	return (ALIVE);
}

int				do_taking_fork(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	pthread_mutex_lock(&philo->setting->fork[philo->left_fork]);
	philo->status = FORKING;
	print_status(philo);
	return (ALIVE);
}

int				do_eat(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	pthread_mutex_lock(&philo->setting->fork[philo->right_fork]);
	philo->status = EATING;
	gettimeofday(&philo->time_last_ate, NULL);
	print_status(philo);
	sleep_for_ms(philo->setting->time_to_eat);
	++philo->ate_count;
	if (eat_enough(philo))
		philo->status = FULL;
	pthread_mutex_unlock(&philo->setting->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->setting->fork[philo->right_fork]);
	return (ALIVE);
}

t_bool			eat_enough(t_philo *philo)
{
	if (philo->setting->number_of_times_each_philosopher_must_eat != NO_LIMIT
		&& philo->ate_count >=
		philo->setting->number_of_times_each_philosopher_must_eat)
		return (TRUE);
	return (FALSE);
}

int				do_think(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	philo->status = THINKING;
	print_status(philo);
	return (ALIVE);
}
