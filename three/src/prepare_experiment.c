#include "three.h"

void	prepare_experiment(t_setup *setup)
{
	init_semaphore(setup);
	init_philosophers(setup);
}

void	init_philosophers(t_setup *setup)
{
	int		num;
	int		i;
	t_philo	*philo;
	long	start_time;

	num = setup->number_of_philosophers;
	setup->philo = malloc(sizeof(t_philo) * num);
	if (setup->philo == NULL)
		error_unexpected();
	philo = setup->philo;
	start_time = get_m_second();
	i = -1;
	while (++i < num)
	{
		philo[i].number = i + 1;
		philo[i].ate_count = 0;
		philo[i].status = NOTHING;
		philo[i].setup = setup;
	}
}

void	init_semaphore(t_setup *setup)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	setup->fork = sem_open("/fork", O_CREAT | O_EXCL, 0777,
							setup->number_of_philosophers);
	setup->print_sem = sem_open("/print", O_CREAT | O_EXCL, 0777, 1);
}
