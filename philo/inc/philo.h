/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/15 17:02:14 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct	s_philo
{
	int	n_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_count;
}				t_philo;

typedef enum	e_status
{
	SUCCESS,
	FAILURE
}				t_status;

/*---------------------------UTILS--------------------------------------------*/
int	ft_atoi(const char *nptr, t_status *status);
int	ft_isdigit(int c);

#endif
