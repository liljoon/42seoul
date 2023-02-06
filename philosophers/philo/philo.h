/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:48:29 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/05 21:40:40 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_timeval;

typedef struct s_philo_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				who_died;
	pthread_mutex_t	*mutex_fork;
	t_timeval		start_time;
}	t_philo_info;

typedef struct s_philo
{
	int				idx;
	int				state;	// 0 : sleeping | 1 : thinking | 2 : eating | -1 : printed
	int				ate_num;
	t_philo_info	*philo_info;
	t_timeval		last_ate_time;
}	t_philo;

int		ft_atoi(const char *str);

void	start_philo(t_philo *philos);

int		left(int idx, int n);
int		right(int idx, int n);

#endif
