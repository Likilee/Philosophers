/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:43:43 by kilee             #+#    #+#             */
/*   Updated: 2021/04/08 15:07:51 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	error_arguments()
{
	printf("Error: wrong arguments\n");
	exit(0);
}

// int		error_arg_value(void)
// {
// 	printf("Error: Wrong argument value\n");
// 	return (0);
// }

int		error_unexpected(void)
{
	printf("Error: Unexpectected\n");
	exit(0);
}

// void	*free_setting_and_return_null(t_setup *setting)
// {
// 	free(setting);
// 	return (NULL);
// }
