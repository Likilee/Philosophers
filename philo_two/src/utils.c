/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:34 by kilee             #+#    #+#             */
/*   Updated: 2021/04/09 18:08:32 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int				ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;
	int		digit_count;

	i = 0;
	sign = 1;
	num = 0;
	digit_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
		sign *= str[i++] == '+' ? 1 : -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + str[i] - '0';
		++i;
		++digit_count;
		if (digit_count == 20)
			return (sign == -1) ? 0 : -1;
	}
	return (num * sign);
}

sem_t			*init_fork(int number_of_fork)
{
	sem_t	*fork;

	sem_unlink("/fork");
	fork = sem_open("/fork", O_CREAT | O_EXCL, 0777, number_of_fork);
	if (fork == NULL)
		return (NULL);
	return (fork);
}

sem_t			*init_print_sem(void)
{
	sem_t	*print_sem;

	sem_unlink("/print");
	print_sem = sem_open("/print", O_CREAT | O_EXCL, 0777, 1);
	if (print_sem == NULL)
		return (NULL);
	return (print_sem);
}

void			destroy_fork(pthread_mutex_t *fork, int number_of_fork)
{
	int		i;

	i = 0;
	while (i < number_of_fork)
		pthread_mutex_destroy(&fork[i++]);
}

void			init_philo(t_philo *philo, int number, t_setting *setting)
{
	philo->number = number;
	philo->ate_count = 0;
	philo->setting = setting;
	philo->time_last_ate = setting->time_start_experiment;
	philo->status = NOTHING;
}
