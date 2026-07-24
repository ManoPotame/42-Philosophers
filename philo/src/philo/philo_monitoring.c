/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:52:11 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 15:15:23 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dying_check(int i, t_program *program)
{
	pthread_mutex_lock(&program->meal_lock);
	if (get_current_time() - program->philos[i].start_time
		- program->philos[i].last_meal >= program->philos[i].time_to_die)
	{
		pthread_mutex_unlock(&program->meal_lock);
		pthread_mutex_lock(&program->stop_lock);
		program->stop_flag = 1;
		pthread_mutex_unlock(&program->stop_lock);
		pthread_mutex_lock(&program->write_lock);
		printf("%zu %d died\n", get_current_time()
			- program->philos[i].start_time, program->philos[i].id);
		pthread_mutex_unlock(&program->write_lock);
		return (1);
	}
	return (0);
}

void	monitoring(t_program *program)
{
	int	i;
	int	finish;

	while (1)
	{
		i = -1;
		finish = 0;
		while (++i < program->n_philo)
		{
			if (dying_check(i, program) == 1)
				return ;
			if (program->num_times_to_eat && program->philos[i].meals_eaten
				>= program->num_times_to_eat)
				finish++;
			pthread_mutex_unlock(&program->meal_lock);
		}
		if (finish == program->n_philo)
		{
			pthread_mutex_lock(&program->stop_lock);
			program->stop_flag = 1;
			pthread_mutex_unlock(&program->stop_lock);
			return ;
		}
		ft_usleep(1);
	}
}
