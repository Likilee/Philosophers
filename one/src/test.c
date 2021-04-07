#include "one.h"

void	print_setting(t_setting *setting)
{
	printf("==== TEST PRINT SETTING ====\n");
	printf("NUM_of_philo  : %d\n", setting->number_of_philosophers);
	printf("TIME_to_die   : %d\n", setting->time_to_die);
	printf("TIME_to_eat   : %d\n", setting->time_to_eat);
	printf("TIME_to_sleep : %d\n", setting->time_to_sleep);
	printf("NUM_of_eat    : %d\n", setting->number_of_times_each_philosopher_must_eat);
	printf("===========================\n\n");

}

void	minus_time_test()
{
	t_timeval		end;
	t_timeval		begin;

	gettimeofday(&begin, NULL);
	usleep(1000 * 1000);
	gettimeofday(&end, NULL);
	printf("End - Begin must be 1000ms\nresult: %ld\n", minus_time(&end, &begin));
}
