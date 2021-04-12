/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:45 by kilee             #+#    #+#             */
/*   Updated: 2021/04/12 10:31:46 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

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
