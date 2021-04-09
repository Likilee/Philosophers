/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:56:28 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 18:08:32 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		print_status(t_philo *philo)
{
	sem_wait(philo->setting->print_sem);
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
	sem_post(philo->setting->print_sem);
}
