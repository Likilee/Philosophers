#include "three.h"

void		clear(t_setup *setup)
{
	int		i;

	i = -1;
	free(setup->philo);
	sem_close(setup->fork);
	sem_close(setup->print_sem);
}
