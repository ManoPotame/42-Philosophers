/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:21 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/17 11:52:25 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_struct(t_philo *philo, char **av, t_status *status)
{
	philo->n_philo = ft_atoi(av[1], status);
	philo->die_time = ft_atoi(av[2], status);
	philo->eat_time = ft_atoi(av[3], status);
	philo->sleep_time = ft_atoi(av[4], status);
	if (av[5])
		philo->eat_time = ft_atoi(av[5], status);
	if (*status > SUCCESS)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_philo		philo;
	t_status	status;

	status = SUCCESS;
	if (ac < 5 || ac > 6)
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	if (fill_struct(&philo, av, &status) == 1 && status > SUCCESS)
	{
		write(2, "Error: Invalid argument input\n", 30);
		return (1);
	}
	int i = 0;
	while()
	{

	}
}
