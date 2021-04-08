/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:42 by kilee             #+#    #+#             */
/*   Updated: 2021/04/08 13:59:07 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

// int		main(int ac, char *av[])
// {
// 	t_setup	*setting;

// 	if (ac != 5 && ac != 6)
// 		return (error_arg_count(ac));
// 	setting = parse_argv(ac, av);
// 	init_semaphore(setting);
// 	if (setting == NULL)
// 		return (error_arg_value());
// 	print_setup(setting);
// 	if (start_experiment(setting) == -1)
// 		return (error_unexpected());
// 	return (0);
// }

int		main(int ac, char *av[])
{
	t_setup	setup;

	if (is_valid_arguments(ac, av))
	{
		parse_arguments(&setup, ac, av);
		prepare_experiment();
		run_experiment();
		clear_experiment();
	}
	else
		error_arguments();
	return (0);
}

t_bool	is_valid_arguments(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (FALSE);
	if (ft_atoi(av[1]) <= 0 ||
		ft_atoi(av[2]) <= 0 ||
		ft_atoi(av[3]) <= 0 ||
		ft_atoi(av[4]) <= 0)
		return (FALSE);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (FALSE);
	return (TRUE);
}
