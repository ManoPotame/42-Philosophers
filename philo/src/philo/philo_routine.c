/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:36:17 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 15:19:45 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	safe_print("has taken a fork", philo);
	ft_usleep(philo->time_to_die + 1);
}

void	*routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->r_fork == philo->l_fork)
		one_philo(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat / 2);
	while (check_stop_flag(philo) == 0)
	{
		lock_forks(philo);
		pthread_mutex_lock(philo->meal_lock);
		philo->last_meal = get_current_time() - philo->start_time;
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->meal_lock);
		safe_print("is eating", philo);
		ft_usleep(philo->time_to_eat);
		unlock_forks(philo);
		safe_print("is sleeping", philo);
		ft_usleep(philo->time_to_sleep);
		safe_print("is thinking", philo);
		think(philo);
	}
	return (NULL);
}
