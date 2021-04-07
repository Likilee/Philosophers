/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:43:43 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 14:49:24 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		error_arg_count(int ac)
{
	printf("Error: Wrong argument amount\n : %d", ac - 1);
	return (0);
}

int		error_arg_value(void)
{
	printf("Error: Wrong argument value\n");
	return (0);
}

int		error_unexpected(void)
{
	printf("Error: Unexpectected\n");
	return (0);
}

void	*free_setting_and_return_null(t_setting *setting)
{
	free(setting);
	return (NULL);
}
