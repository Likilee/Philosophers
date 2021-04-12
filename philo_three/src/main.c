/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:52:42 by kilee             #+#    #+#             */
/*   Updated: 2021/04/12 10:47:14 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

int		main(int ac, char *av[])
{
	t_setup	setup;

	if (!is_valid_arguments(ac, av))
		error_arguments();
	parse_arguments(&setup, ac, av);
	prepare_experiment(&setup);
	run_experiment(&setup);
	clear(&setup);
	return (0);
}
