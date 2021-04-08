/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:58:20 by kilee             #+#    #+#             */
/*   Updated: 2021/04/08 13:59:07 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	print_setup(t_setup *setting)
{
	printf("==== TEST PRINT SETTING ====\n");
	printf("NUM_of_philo  : %d\n", setting->number_of_philosophers);
	printf("TIME_to_die   : %d\n", setting->time_to_die);
	printf("TIME_to_eat   : %d\n", setting->time_to_eat);
	printf("TIME_to_sleep : %d\n", setting->time_to_sleep);
	printf("NUM_of_eat    : %d\n",
			setting->number_of_must_eat);
	printf("===========================\n\n");
}

void	print_timeval(t_timeval time, const char *s)
{
	long	millisecond;

	millisecond = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%s :", s);
	printf(" %ld ms\n", millisecond);
}

void	minus_time_test(void)
{
	t_timeval		end;
	t_timeval		begin;

	gettimeofday(&begin, NULL);
	sleep_for_ms(1000);
	gettimeofday(&end, NULL);
	printf("End - Begin must be 1000ms\nresult: %ld\n",
			minus_time(&end, &begin));
}
