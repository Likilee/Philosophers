/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:49:28 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 18:27:17 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			start_experiment(t_setting *setting)
{
	pthread_t		*philo_thread;
	t_philo			*philo;
	int				i;

	philo_thread = malloc(sizeof(pthread_t) * setting->number_of_philosophers);
	philo = malloc(sizeof(t_philo) * setting->number_of_philosophers);
	if (philo_thread == NULL || philo == NULL)
		return (-1);
	i = -1;
	while (++i < setting->number_of_philosophers)
		init_philo(&philo[i], i + 1, setting);
	i = -1;
	gettimeofday(&setting->time_start_experiment, NULL);
	while (++i < setting->number_of_philosophers)
		pthread_create(&philo_thread[i], NULL,
						philo_do_his_job, (void *)&philo[i]);
	i = -1;
	while (++i < setting->number_of_philosophers)
		pthread_join(philo_thread[i], NULL);
	sem_close(setting->fork);
	sem_close(setting->print_sem);
	return (0);
}

void		*philo_do_his_job(void *philo_data)
{
	t_philo		*philo;
	pthread_t	dead_checker;

	philo = (t_philo *)philo_data;
	if (philo->number & 1)
		sleep_for_ms(10);
	philo->time_last_ate = philo->setting->time_start_experiment;
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
	return (NULL);
}

void		*am_i_dead(void *philo_data)
{
	t_philo		*philo;
	t_timeval	now;

	philo = (t_philo *)philo_data;
	while (1)
	{
		if (philo->status == FULL || philo->setting->someone_dead == TRUE)
			break ;
		gettimeofday(&now, NULL);
		if (minus_time(&now, &philo->time_last_ate)
			> philo->setting->time_to_die)
		{
			philo->status = DYING;
			print_status(philo);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
