#include "one.h"

void		sleep_for_ms(int millisecond)
{
	t_timeval	begin;
	t_timeval	now;
	long		base;

	gettimeofday(&begin, NULL);
	base = begin.tv_sec * 1000 + begin.tv_usec / 1000;
	// printf("begin: %d\n", begin.tv_usec);
	while (1)
	{
		gettimeofday(&now, NULL);
		if ((now.tv_sec * 1000 + now.tv_usec / 1000) -
			(base) >=
			millisecond)
			return ;
	}
}

long		minus_time(t_timeval *end, t_timeval *begin)
{
	long		time;

	time = (end->tv_sec * 1000 + end->tv_usec / 1000)
		- (begin->tv_sec * 1000 + begin->tv_usec / 1000);
	return (time);
}
