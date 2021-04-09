/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:56:28 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 17:57:27 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void		print_status(t_philo *philo, long now)
{
	sem_wait(philo->setup->print_sem);
	if (philo->status == FORKING)
		print_take_fork(philo, now);
	else if (philo->status == EATING)
		print_is_eating(philo, now);
	else if (philo->status == SLEEPING)
		print_is_sleeping(philo, now);
	else if (philo->status == THINKING)
		print_is_thinking(philo, now);
	else if (philo->status == DYING)
	{
		// printf("11\n");
		print_died(philo, now);
		// printf("22\n");
		return ;
	}
	sem_post(philo->setup->print_sem);
}
