/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:23:11 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/15 17:00:24 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int	i;
	int	result;

	if (!nptr)
		return (0);
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		*status = FAILURE;
	if (nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (ft_isdigit(nptr[i]) == 1 || status)
		{
			*status = FAILURE;
			return (-1);
		}
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result);
}

