/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:23:11 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/20 17:35:07 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief Funcion that convert ASCII characters to INT digits.
 *
 * @param nptr The string receves has argument.
 * @return int
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr, t_status *status)
{
	int		i;
	long	result;

	if (!nptr)
		return (0);
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]) == 0)
	{
		result = (result * 10) + nptr[i] - '0';
		if (result > INT_MAX)
		{
			*status = FAILURE;
			return (0);
		}
		i++;
	}
	return ((int)result);
}

