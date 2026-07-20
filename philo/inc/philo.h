/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/20 18:14:58 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				*stop;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*stop_lock;
	pthread_mutex_t	*meal_lock;
	size_t			start_time;
	pthread_t		thread;
}				t_philo;

typedef enum e_status
{
	SUCCESS,
	FAILURE,
	ALLOC_FAIL,
	MUTEX_FAIL
}	t_status;

/**
 * @brief
 * @param stop_flag:
 */
typedef struct	s_program
{
	int				n_philo;
	int				stop_flag;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				num_times_to_eat;
	t_status		status;
}	t_program;


/*---------------------------UTILS--------------------------------------------*/
int		ft_atoi(const char *nptr, t_status *status);
int		ft_isdigit(int c);
size_t	get_current_time(void)

#endif
