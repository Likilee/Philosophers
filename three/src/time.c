/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:22 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 16:03:54 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void		sleep_for_ms(int millisecond)
{
	long		begin;
	long		now;

	begin = get_m_second();
	while (1)
	{
		now = get_m_second();
		if (now - begin >= millisecond)
			return ;
		usleep(500);
	}
	// usleep(millisecond * 1000);
}

long		get_m_second()
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

long		minus_time(t_timeval *end, t_timeval *begin)
{
	long		time;

	time = (end->tv_sec * 1000 + end->tv_usec / 1000)
		- (begin->tv_sec * 1000 + begin->tv_usec / 1000);
	return (time);
}
