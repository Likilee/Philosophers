/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:56:28 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 14:56:35 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void		print_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->setting->print_mutex);
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
