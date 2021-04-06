#include "one.h"

pthread_mutex_t	*init_fork(int number_of_fork)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = (pthread_mutex_t	*)malloc(sizeof(pthread_mutex_t) * number_of_fork);
	if (fork == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_fork)
		pthread_mutex_init(&fork[i++], NULL);
	return (fork);
}

void	destroy_fork(pthread_mutex_t *fork, int number_of_fork)
{
	int		i;

	i = 0;
	while (i < number_of_fork)
		pthread_mutex_destroy(&fork[i++]);
}

void	init_philo(t_philo *philo, int number, t_setting *setting)
{
	philo->number = number;
	philo->ate_count = 0;
	philo->setting = setting;
	philo->left_fork = philo->number - 1;
	philo->right_fork = philo->number - 2;
	if (philo->right_fork == -1)
		philo->right_fork = setting->number_of_philosophers - 1;
	philo->time_last_ate = setting->time_start_experiment;
	philo->ate_enough = FALSE;
	philo->status = NOTHING;
}

int		do_sleep(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	philo->status = SLEEPING;
	print_status(philo);
	sleep_for_ms(philo->setting->time_to_sleep);
	return (ALIVE);
}

int		do_taking_fork(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	pthread_mutex_lock(&philo->setting->fork[philo->left_fork]);
	philo->status = FORKING;
	print_status(philo);
	return (ALIVE);
}

int		do_eat(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	pthread_mutex_lock(&philo->setting->fork[philo->right_fork]);
	philo->status = EATING;
	gettimeofday(&philo->time_last_ate, NULL);
	print_status(philo);
	// usleep(philo->setting->time_to_eat * 1000);
	sleep_for_ms(philo->setting->time_to_eat);
	++philo->ate_count;
	if (philo->setting->number_of_times_each_philosopher_must_eat != NO_LIMIT &&
		philo->ate_count >= philo->setting->number_of_times_each_philosopher_must_eat)
	{
		philo->ate_enough = TRUE;
		return (FULL);
	}
	pthread_mutex_unlock(&philo->setting->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->setting->fork[philo->right_fork]);
	return (ALIVE);
}

int		do_think(t_philo *philo)
{
	if (philo->setting->someone_dead == TRUE)
		return (DEAD);
	philo->status = THINKING;
	print_status(philo);
	return (ALIVE);
}

void	*am_i_dead(void *philo_data)
{
	t_philo		*philo;
	t_timeval	now;

	philo = (t_philo *)philo_data;
	while (1)
	{
		sleep_for_ms(1); // 이거로 해결..
		if (philo->ate_enough == TRUE || philo->setting->someone_dead == TRUE)
			break ;
		gettimeofday(&now, NULL);
		// print_timeval(now, "now");
		// print_timeval(philo->time_last_ate, "last ate");
		// printf("minus before: %ld\n\n", minus_time(now, philo->time_last_ate));
		if (minus_time(&now, &philo->time_last_ate) - philo->setting->time_to_die > 0)
		{
			// print_timeval(now, "now");
			// print_timeval(philo->time_last_ate, "last ate");
			// printf("minus: %ld\n", minus_time(now, philo->time_last_ate));
			// printf("timetodie: %d\n", philo->setting->time_to_die);
			philo->status = DYING;
			print_status(philo);
			break;
		}
	}
	// if (philo->setting->someone_dead == TRUE)
	// 	pthread_mutex_unlock(&philo->setting->print_mutex);
	return (NULL);
}

void	*philo_do_his_job(void *philo_data)
{
	t_philo		*philo;
	pthread_t	dead_checker;

	philo = (t_philo *)philo_data;
	if (philo->number % 2 == 0)
		sleep_for_ms(10);
		// do_sleep(philo);
	pthread_create(&dead_checker, NULL, am_i_dead, (void *)philo);
	while (1)
	{
		if (do_taking_fork(philo) != ALIVE)
			break ;
		if (do_eat(philo) != ALIVE)
			break ;
		if (do_sleep(philo) != ALIVE)
			break ;
		if (do_think(philo) != ALIVE)
			break ;
	}
	pthread_join(dead_checker, NULL);
	return (NULL);
}

int		start_experiment(t_setting *setting)
{
	pthread_t		*philosopher;
	t_philo			*philo;
	int				i;

	philosopher = (pthread_t *)malloc(sizeof(pthread_t) * setting->number_of_philosophers);
	philo = (t_philo *)malloc(sizeof(t_philo) * setting->number_of_philosophers);
	if (philosopher == NULL || philo == NULL)
		return (-1);
	i = -1;
	while (++i < setting->number_of_philosophers)
		init_philo(&philo[i], i + 1, setting);
	i = -1;
	gettimeofday(&setting->time_start_experiment, NULL);
	while (++i < setting->number_of_philosophers)
	{
		// init_philo(&philo[i], i + 1, setting);
		pthread_create(&philosopher[i], NULL, philo_do_his_job, (void *)&philo[i]);
	}
	i = -1;
	while (++i < setting->number_of_philosophers)
		pthread_join(philosopher[i], NULL);
	return (0);
}
