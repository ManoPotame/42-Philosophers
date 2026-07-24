/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:24:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/07/24 18:03:29 by mcrenn           ###   ########.fr       */
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
typedef struct s_program
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

/*---------------------------STRUCT-------------------------------------------*/
t_status	fill_struct(char **av, t_program *program);
void		destroy_struct(t_program *program);

/*---------------------------PHILO--------------------------------------------*/
void		*routine(void *input);
void		monitoring(t_program *program);
int			check_stop_flag(t_philo *philo);

/*---------------------------UTILS--------------------------------------------*/
int			ft_atoi(const char *nptr, t_status *status);
int			ft_isdigit(int c);
void		*ft_memset(void *s, int c, size_t n);
int			ft_usleep(size_t milliseconds);
void		safe_print(const char *str, t_philo *philo);
size_t		get_current_time(void);

/*---------------------------UTILS PHILO--------------------------------------*/
void		lock_forks(t_philo *philo);
void		unlock_forks(t_philo *philo);
void		think(t_philo *philo);

/*---------------------------ERROR MANAGER------------------------------------*/
void		error_manager(t_program *program);

#endif
