/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:54 by kilee             #+#    #+#             */
/*   Updated: 2021/04/12 10:47:14 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

/*
** exit code 0 : FULL 로 끝난애
** exit code 1 : DEAD 로 끝난애
*/

void		manage_process(t_setup *setup)
{
	int		i;
	int		status;
	int		full_philo;
	t_philo	*philo;

	full_philo = 0;
	while (1)
	{
		i = -1;
		while (++i < setup->number_of_philosophers)
		{
			status = -1;
			philo = &setup->philo[i];
			waitpid(philo->pid, &status, WNOHANG);
			if (is_full_philo(status))
				++full_philo;
			if (is_dead_philo(status)
				|| full_philo == setup->number_of_philosophers)
			{
				finish_experiment(setup);
				return ;
			}
		}
		usleep(500);
	}
}

t_bool		is_full_philo(int status)
{
	if (status == 0)
		return (TRUE);
	return (FALSE);
}

t_bool		is_dead_philo(int status)
{
	if (status / 256 == 1)
		return (TRUE);
	return (FALSE);
}

void		finish_experiment(t_setup *setup)
{
	int		i;

	i = -1;
	while (++i < setup->number_of_philosophers)
		kill(setup->philo[i].pid, SIGKILL);
}
