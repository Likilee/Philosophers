/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:34 by kilee             #+#    #+#             */
/*   Updated: 2021/04/07 14:58:10 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

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
	philo->left_fork = philo->number - 1;
	philo->right_fork = philo->number - 2;
	if (philo->right_fork == -1)
		philo->right_fork = setting->number_of_philosophers - 1;
	philo->time_last_ate = setting->time_start_experiment;
	philo->status = NOTHING;
}
