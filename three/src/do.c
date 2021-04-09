/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:43:41 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 15:48:57 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

int				do_sleep(t_philo *philo)
{
	long	now;

	now = get_m_second();
	philo->status = SLEEPING;
	print_status(philo, now);
	sleep_for_ms(philo->setup->time_to_sleep);
	return (ALIVE);
}

int				do_taking_fork(t_philo *philo)
{
	long	now;

	sem_wait(philo->setup->fork);
	now = get_m_second();
	philo->status = FORKING;
	print_status(philo, now);
	return (ALIVE);
}

int				do_eat(t_philo *philo)
{
	long	now;

	sem_wait(philo->setup->fork);
	now = get_m_second();
	philo->time_last_ate = now;
	philo->status = EATING;
	print_status(philo, now);
	sleep_for_ms(philo->setup->time_to_eat);
	++philo->ate_count;
	if (eat_enough(philo))
		philo->status = FULL;
	sem_post(philo->setup->fork);
	sem_post(philo->setup->fork);
	return (ALIVE);
}

t_bool			eat_enough(t_philo *philo)
{
	if (philo->setup->number_of_must_eat != NO_LIMIT
		&& philo->ate_count >=
		philo->setup->number_of_must_eat)
		return (TRUE);
	return (FALSE);
}

int				do_think(t_philo *philo)
{
	long	now;

	now = get_m_second();
	// if (philo->setup->someone_dead == TRUE)
	// 	return (DEAD);
	philo->status = THINKING;
	print_status(philo, now);
	return (ALIVE);
}
