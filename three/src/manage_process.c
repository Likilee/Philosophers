#include "three.h"

/*
** exit code 0 : FULL 로 끝난애
** exit code 1 : DEAD 로 끝난애
*/
void		manage_process(t_setup *setup)
{
	int		i;
	int		status;
	int		full_philo;
	t_philo	*philo;

	full_philo = 0;
	while (1)
	{
		i = -1;
		while (++i < setup->number_of_philosophers)
		{
			status = -1;
			philo = &setup->philo[i];
			waitpid(philo->pid, &status, WNOHANG);
			if (is_full_philo(status))
				++full_philo;
			if (status != -1 || full_philo == setup->number_of_philosophers)
			{
				finish_experiment(setup);
				return ;
			}
		}
		// if (is_dead_philo(status) || full_philo == setup->number_of_philosophers)
		// {
		// 	return ;
		// }
		// write(1, "hi\n", 3);
		// printf("hi");
		// usleep(1000);
	}
}

t_bool		is_full_philo(int status)
{
	if (status == 0)
		return (TRUE);
	return (FALSE);
}

t_bool		is_dead_philo(int status)
{
	if (status / 256 == 1)
		return (TRUE);
	return (FALSE);
}

void		finish_experiment(t_setup *setup)
{
	int		i;

	i = -1;
	while (++i < setup->number_of_philosophers)
		kill(setup->philo[i].pid, SIGKILL);
}
