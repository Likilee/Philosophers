/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:42 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 12:57:45 by kilee            ###   ########.fr       */
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

	if (!is_valid_arguments(ac, av))
		error_arguments();
	parse_arguments(&setup, ac, av);
	print_setup(&setup);
	prepare_experiment(&setup);
	run_experiment(&setup);
	clear(&setup);
	return (0);
}
