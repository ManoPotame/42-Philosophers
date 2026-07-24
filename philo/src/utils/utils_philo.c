/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:47:07 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 18:11:06 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	long	time;

	time = philo->time_to_die - philo->time_to_eat - philo->time_to_sleep - 10;
	if (time < 0)
		time = 0;
	else if (time > 600)
		time = 200;
	ft_usleep((size_t)time / 2);
}

int	check_stop_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->stop_lock);
	if (*philo->stop == 1)
	{
		pthread_mutex_unlock(philo->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->stop_lock);
	return (0);
}

void	safe_print(const char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (check_stop_flag(philo) == 0)
		printf("%zu %d %s\n", get_current_time()
			- philo->start_time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	lock_forks(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
	{
		pthread_mutex_lock(philo->l_fork);
		safe_print("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
		safe_print("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		safe_print("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		safe_print("has taken a fork", philo);
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}
