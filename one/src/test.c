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
