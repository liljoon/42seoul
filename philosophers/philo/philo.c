/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:49:26 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/06 13:20:06 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	t_timeval	now_time;
	long		diff_ms;
	long		starving_time;

	gettimeofday(&now_time, NULL);
	diff_ms = (now_time.tv_sec - philo->philo_info->start_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - philo->philo_info->start_time.tv_usec) / 1000;
	starving_time = (now_time.tv_sec - philo->last_ate_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - philo->last_ate_time.tv_usec) / 1000;
	if (starving_time > philo->philo_info->time_to_die)
	{
		printf("%ld %d died\n", diff_ms, philo->idx + 1);
		philo->philo_info->who_died = 1;
		//philo->state = -1;
		return ;
	}

}

void	monitoring(t_philo *philos)
{
	int	idx;

	while (1)
	{
		idx = 0;
		while (idx < philos->philo_info->num_philo)
		{
			check_die(philos + idx);
			if (philos->philo_info->who_died == 1)
				return ;
			idx++;
		}
		usleep(100);
	}
}

void	sleeping(t_philo *philo)
{
	t_timeval	now_time;
	long		diff_ms;

	gettimeofday(&now_time, NULL);
	diff_ms = (now_time.tv_sec - philo->philo_info->start_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - philo->philo_info->start_time.tv_usec) / 1000;
	//philo->state = 0;
	printf("%ld %d is sleeping\n", diff_ms, philo->idx + 1);
	usleep(philo->philo_info->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{

	t_timeval	now_time;
	long		diff_ms;

	gettimeofday(&now_time, NULL);
	diff_ms = (now_time.tv_sec - philo->philo_info->start_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - philo->philo_info->start_time.tv_usec) / 1000;
	printf("%ld %d is thinking\n", diff_ms, philo->idx + 1);
	//philo->state = 1;
}

void	eating(t_philo *philo)
{
	int			right_philo;
	t_timeval	now_time;
	long		diff_ms;

	right_philo = right(philo->idx, philo->philo_info->num_philo);
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[philo->idx]));
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[right_philo]));
	}
	else
	{
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[right_philo]));
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[philo->idx]));
	}
	//philo->state = 2;
	if (philo->philo_info->who_died == 1)
			return ;
	gettimeofday(&now_time, NULL);
	diff_ms = (now_time.tv_sec - philo->philo_info->start_time.tv_sec) * 1000 \
	+ (now_time.tv_usec - philo->philo_info->start_time.tv_usec) / 1000;
	printf("%ld %d is eating\n", diff_ms, philo->idx + 1);
	usleep(philo->philo_info->time_to_eat * 1000);
	philo->ate_num += 1;
	gettimeofday(&(philo->last_ate_time), NULL);
	pthread_mutex_unlock(&(philo->philo_info->mutex_fork[philo->idx]));
	pthread_mutex_unlock(&(philo->philo_info->mutex_fork[right_philo]));
}

void	philosopher(t_philo *philo)
{
	if (philo->idx % 2 == 1)
		usleep(100);
	while (1)
	{
		thinking(philo);
		if (philo->philo_info->who_died == 1)
			break ;
		eating(philo);
		if (philo->philo_info->who_died == 1)
			break ;
		sleeping(philo);
		if (philo->philo_info->who_died == 1)
			break ;
	}
}

void	start_philo(t_philo *philos)
{
	int			idx;
	pthread_t	*thread;

	thread = malloc(sizeof(thread) * (philos->philo_info->num_philo + 1));
	idx = 0;
	gettimeofday(&(philos->philo_info->start_time), NULL);
	while (idx < philos->philo_info->num_philo)
	{
		philos[idx].last_ate_time = philos->philo_info->start_time;
		pthread_create(thread + idx, NULL, (void *)philosopher, philos + idx);
		idx++;
	}
	pthread_create(thread + idx, NULL, (void *)monitoring, philos);
	idx = 0;
	while (idx < philos->philo_info->num_philo + 1)
	{
		pthread_join(thread[idx], NULL);
		idx++;
	}
}
