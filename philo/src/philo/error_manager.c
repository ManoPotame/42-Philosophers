/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:24:32 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 18:00:37 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manager(t_program *program)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->stop_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	if (program->forks)
	{
		while (i < program->n_philo)
		{
			pthread_mutex_destroy(&program->forks[i]);
			i++;
		}
		free(program->forks);
	}
	if (program->philos)
		free(program->philos);
	if (program->status == FAILURE)
		write(2, "Error: Bad Arguments.\n", 22);
	if (program->status == ALLOC_FAIL)
		write(2, "Error: Allocation failed.\n", 26);
	if (program->status == MUTEX_FAIL)
		write(2, "Error: Initialisation of mutex failed.\n", 39);
}
