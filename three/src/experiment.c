/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:49:28 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 17:57:20 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void			run_experiment(t_setup *setup)
{
	int			i;
	long		start_time;

	start_time = get_m_second();
	i = -1;
	while(++i < setup->number_of_philosophers)
	{
		setup->philo[i].pid = fork();
		if (setup->philo[i].pid == 0)
			break;
	}
	if (setup->philo[i].pid < 0)
		error_unexpected();
	setup->philo[i].time_start = start_time;
	if (i != setup->number_of_philosophers)
		philo_do_his_job(&setup->philo[i]);
	else
		manage_process(setup);
}

void		philo_do_his_job(t_philo *philo)
{
	pthread_t	dead_checker;

	philo->time_last_ate = get_m_second();
	// if (philo->number % 2 == 0)
	// 	sleep_for_ms(1);
	pthread_create(&dead_checker, NULL, am_i_dead, (void *)philo);
	while (1)
	{
		if (do_taking_fork(philo) == DEAD)
			break ;
		if (do_eat(philo) == DEAD || philo->status == FULL)
			break ;
		if (do_sleep(philo) == DEAD)
			break ;
		if (do_think(philo) == DEAD)
			break ;
	}
	pthread_join(dead_checker, NULL);
}

void		*am_i_dead(void *philo_data)
{
	t_philo		*philo;
	long		now;

	philo = (t_philo *)philo_data;
	while (1)
	{
		if (philo->status == FULL)
			exit(0) ;
		now = get_m_second();
		if (now - philo->time_last_ate >= philo->setup->time_to_die)
		{
			philo->status = DYING;
			// printf("here1\n");
			print_status(philo, now);
			// printf("here2\n");
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
