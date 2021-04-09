/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:42 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 18:08:32 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		main(int ac, char *av[])
{
	t_setting	*setting;

	if (ac != 5 && ac != 6)
		return (error_arg_count(ac));
	setting = parse_argv(ac, av);
	if (setting == NULL)
		return (error_arg_value());
	print_setting(setting);
	if (start_experiment(setting) == -1)
		return (error_unexpected());
	return (0);
}
