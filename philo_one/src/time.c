/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:22 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 18:02:36 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void		sleep_for_ms(int millisecond)
{
	t_timeval	begin;
	t_timeval	now;
	long		base;

	gettimeofday(&begin, NULL);
	base = begin.tv_sec * 1000 + begin.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&now, NULL);
		if ((now.tv_sec * 1000 + now.tv_usec / 1000) -
			(base) >=
			millisecond)
			return ;
		usleep(500);
	}
}

long		minus_time(t_timeval *end, t_timeval *begin)
{
	long		time;

	time = (end->tv_sec * 1000 + end->tv_usec / 1000)
		- (begin->tv_sec * 1000 + begin->tv_usec / 1000);
	return (time);
}
