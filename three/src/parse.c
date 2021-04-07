/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:58 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 15:26:53 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

t_setting	*parse_argv(int ac, char *av[])
{
	t_setting	*setting;

	if (!(setting = (t_setting *)malloc(sizeof(t_setting))))
		return (NULL);
	setting->number_of_philosophers = ft_atoi(av[1]);
	setting->time_to_die = ft_atoi(av[2]);
	setting->time_to_eat = ft_atoi(av[3]);
	setting->time_to_sleep = ft_atoi(av[4]);
	if (setting->number_of_philosophers <= 0 || setting->time_to_die <= 0
		|| setting->time_to_eat <= 0 || setting->time_to_sleep < 0)
		return (free_setting_and_return_null(setting));
	if (ac == 6)
	{
		setting->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		if (setting->number_of_times_each_philosopher_must_eat <= 0)
			return (free_setting_and_return_null(setting));
	}
	else
		setting->number_of_times_each_philosopher_must_eat = NO_LIMIT;
	if (!(setting->fork = init_fork(setting->number_of_philosophers)))
		return (free_setting_and_return_null(setting));
	if (!(setting->print_sem = init_print_sem()))
		return (free_setting_and_return_null(setting));
	setting->someone_dead = FALSE;
	return (setting);
}
