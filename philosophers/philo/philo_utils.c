/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:34:08 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/06 19:22:04 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	left(int idx, int n)
{
	return ((idx - 1 + n) % n);
}

int	right(int idx, int n)
{
	return ((idx + 1) % n);
}

long	get_time_diff_ms(t_timeval start_time)
{
	t_timeval	now_time;
	long		diff_ms;

	gettimeofday(&now_time, NULL);
	diff_ms = (now_time.tv_sec - start_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - start_time.tv_usec) / 1000;
	return (diff_ms);
}

void	my_msleep(int ms)
{
	t_timeval	now_time;
	long		diff_ms;

	gettimeofday(&now_time, NULL);
	diff_ms = get_time_diff_ms(now_time);
	while (diff_ms < ms)
	{
		diff_ms = get_time_diff_ms(now_time);
		usleep(100);
	}
}

void	start_philo(t_philo *philos)
{
	int			idx;
	pthread_t	*tid;

	if (philos->philo_info->num_philo == 1)
	{
		printf("%d %d is thinking\n", 0, 1);
		my_msleep(philos->philo_info->time_to_die);
		printf("%d %d died\n", philos->philo_info->time_to_die + 1, 1);
		return ;
	}
	tid = malloc(sizeof(tid) * (philos->philo_info->num_philo + 1));
	idx = 0;
	gettimeofday(&(philos->philo_info->start_time), NULL);
	while (idx < philos->philo_info->num_philo)
	{
		philos[idx].last_ate_time = philos->philo_info->start_time;
		pthread_create(tid + idx, NULL, (void *)philosopher, philos + idx);
		idx++;
	}
	pthread_create(tid + idx, NULL, (void *)monitoring, philos);
	idx = 0;
	while (idx < philos->philo_info->num_philo + 1)
		pthread_join(tid[idx++], NULL);
	free(tid);
}
