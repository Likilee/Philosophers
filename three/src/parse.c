/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:58 by kilee             #+#    #+#             */
/*   Updated: 2021/04/08 13:59:07 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	parse_arguments(t_setup *setup, int ac, char *av[])
{
	setup->number_of_philosophers = ft_atoi(av[1]);
	setup->time_to_die = ft_atoi(av[2]);
	setup->time_to_eat = ft_atoi(av[3]);
	setup->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		setup->number_of_must_eat = ft_atoi(av[5]);
	else
		setup->number_of_must_eat = NO_LIMIT;
}
