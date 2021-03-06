/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:43:43 by kilee             #+#    #+#             */
/*   Updated: 2021/04/12 10:35:30 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	error_arguments(void)
{
	printf("Error: wrong arguments\n");
	exit(0);
}

int		error_unexpected(void)
{
	printf("Error: Unexpectected\n");
	exit(0);
}
