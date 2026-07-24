/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:54:43 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 17:36:35 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	init_mutex(char **av, t_program *program)
{
	program->n_philo = ft_atoi(av[0], &program->status);
	if (program->n_philo < 1 || program->n_philo > 200
		|| program->status == FAILURE)
		program->status = FAILURE;
	if (pthread_mutex_init(&program->stop_lock, NULL))
		program->status = MUTEX_FAIL;
	if (pthread_mutex_init(&program->meal_lock, NULL))
		program->status = MUTEX_FAIL;
	if (pthread_mutex_init(&program->write_lock, NULL))
		program->status = MUTEX_FAIL;
	return (program->status);
}

t_status	check_args(char **av, t_program *program, int i)
{
	program->philos[i].time_to_die = ft_atoi(av[1], &program->status);
	if (program->status > SUCCESS)
		return (program->status);
	program->philos[i].time_to_eat = ft_atoi(av[2], &program->status);
	if (program->status > SUCCESS)
		return (program->status);
	program->philos[i].time_to_sleep = ft_atoi(av[3], &program->status);
	if (program->status > SUCCESS)
		return (program->status);
	return (SUCCESS);
}

t_status	init_philo(char **av, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philo)
	{
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = 0;
		if (check_args(av, program, i) > SUCCESS)
			return (program->status);
		program->philos[i].stop = &program->stop_flag;
		program->philos[i].l_fork = &program->forks[i];
		program->philos[i].r_fork = &program->forks[(i + 1) % program->n_philo];
		program->philos[i].write_lock = &program->write_lock;
		program->philos[i].stop_lock = &program->stop_lock;
		program->philos[i].meal_lock = &program->meal_lock;
		i++;
	}
	if (av[4])
		program->num_times_to_eat = ft_atoi(av[4], &program->status);
	else
		program->num_times_to_eat = 0;
	return (SUCCESS);
}

t_status	fill_struct(char **av, t_program *program)
{
	int	i;

	program->stop_flag = 0;
	program->status = SUCCESS;
	if (av[0][0] == '0' || av[1][0] == '0'
		|| av[2][0] == '0' || av[3][0] == '0')
		return (FAILURE);
	if (init_mutex(av, program) > SUCCESS)
		return (program->status);
	program->forks = malloc(program->n_philo * sizeof(pthread_mutex_t));
	if (!program->forks)
		return (ALLOC_FAIL);
	i = 0;
	while (i < program->n_philo)
	{
		if (pthread_mutex_init(&program->forks[i], NULL))
			return (MUTEX_FAIL);
		i++;
	}
	program->philos = malloc(program->n_philo * sizeof(t_philo));
	if (!program->philos)
		return (ALLOC_FAIL);
	if (init_philo(av, program))
		return (program->status);
	return (SUCCESS);
}

void	destroy_struct(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philo)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&program->stop_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
}
