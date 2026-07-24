/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:21 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 18:10:12 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program	prg;
	int			i;

	if (ac != 5 && ac != 6)
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	ft_memset(&prg, 0, sizeof(t_program));
	if (fill_struct(av + 1, &prg))
	{
		error_manager(&prg);
		return (1);
	}
	i = 0;
	while (i < prg.n_philo)
	{
		prg.philos[i].start_time = get_current_time();
		pthread_create(&prg.philos[i].thread, NULL, &routine, &prg.philos[i]);
		i++;
	}
	monitoring(&prg);
	destroy_struct(&prg);
	free(prg.forks);
	free(prg.philos);
}
