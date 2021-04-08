#include "three.h"

void	prepare_experiment(t_setup *setup)
{
	init_philosophers(setup);
	init_semaphore(setup);
}

void	init_philosophers(t_setup *setup)
{
	int		num;
	int		i;
	t_philo	*philo;

	num = setup->number_of_philosophers;
	setup->philo = malloc(sizeof(t_philo) * num);
	philo = setup->philo;
	
	if (setup->philo == NULL)
		error_unexpected();
	i = -1;
	while (++i < num)
	{
		philo[i]
	}
}
