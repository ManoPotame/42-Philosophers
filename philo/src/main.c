/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:21 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/20 18:18:29 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_status	fill_struct(char **av, t_program *program)
{
	size_t			i;

	program->stop_flag = 0;
	program->status = SUCCESS;
	program->n_philo = ft_atoi(av[0], &program->status);
	if (program->n_philo < 1 || program->n_philo > 200
		|| program->status == FAILURE)
		return (FAILURE);
	if (pthread_mutex_init(&program->stop_lock, NULL))
		return (MUTEX_FAIL);
	if (pthread_mutex_init(&program->meal_lock, NULL))
		return (MUTEX_FAIL);
	if (pthread_mutex_init(&program->write_lock, NULL))
		return (MUTEX_FAIL);
	program->forks = malloc(program->n_philo * sizeof(pthread_mutex_t));
	if (!program->forks)
		return (ALLOC_FAIL);
	i = 0;
	while (i < program->n_philo)
	{
		if (pthread_mutex_init(&program->forks, NULL))
			return (MUTEX_FAIL);
		i++;
	}
	program->philos = malloc(program->n_philo * sizeof(t_philo));
	if (!program->philos)
		return (ALLOC_FAIL);
	i = 0;
	while (i < program->n_philo)
	{
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = 0;
		program->philos[i].time_to_die = ft_atoi(av[1], &program->status);
		program->philos[i].time_to_eat = ft_atoi(av[2], &program->status);
		program->philos[i].time_to_sleep = ft_atoi(av[3], &program->status);
		program->philos[i].stop = &program->stop_flag;
		program->philos[i].l_fork = &program->forks[i];
		program->philos[i].r_fork = &program->forks[(i + 1) % program->n_philo];
		program->philos[i].write_lock = &program->write_lock;
		program->philos[i].stop_lock = &program->stop_lock;
		program->philos[i].meal_lock = &program->meal_lock;
		i++;
	}
	if (av[3])
		program->num_times_to_eat = ft_atoi(av[3], &program->status);
	else
		program->num_times_to_eat = 0;
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
		printf("%zu %d %s\n", philo->start_time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	while (1)
	{
		pthread_mutex_lock(philo->l_fork);

	}

}

int main(int ac, char **av)
{
	t_program	program;
	size_t		i;

	fill_struct(av + 1, &program);
	i = 0;
	while(i < program.n_philo)
	{
		program.philos[i].start_time = get_current_time();
		pthread_create(&program.philos[i].thread, NULL, &routine, &program.philos[i]);
		i++;
	}






	// status = SUCCESS;
	// if (ac != 5 && ac != 6)
	// {
	// 	write(2, "Error: Invalid number of arguments\n", 35);
	// 	return (1);
	// }
	// if (fill_struct(&philo, av, &status) == 1 && status > SUCCESS)
	// {
	// 	write(2, "Error: Invalid argument input\n", 30);
	// 	return (1);
	// }

}
