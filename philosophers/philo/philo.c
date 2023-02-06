/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:49:26 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/06 17:47:47 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	long	diff_ms;

	diff_ms = get_time_diff_ms(philo->philo_info->start_time);
	printf("%ld %d is sleeping\n", diff_ms, philo->idx + 1);
	my_msleep(philo->philo_info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	long	diff_ms;

	diff_ms = get_time_diff_ms(philo->philo_info->start_time);
	printf("%ld %d is thinking\n", diff_ms, philo->idx + 1);
}

void	take_forks(t_philo *philo)
{
	int		right_philo;
	long	diff_ms;

	right_philo = right(philo->idx, philo->philo_info->num_philo);
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[philo->idx]));
		diff_ms = get_time_diff_ms(philo->philo_info->start_time);
		if (philo->philo_info->who_died == 0)
			printf("%ld %d has taken a fork\n", diff_ms, philo->idx + 1);
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[right_philo]));
		diff_ms = get_time_diff_ms(philo->philo_info->start_time);
		if (philo->philo_info->who_died == 0)
			printf("%ld %d has taken a fork\n", diff_ms, philo->idx + 1);
	}
	else
	{
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[right_philo]));
		diff_ms = get_time_diff_ms(philo->philo_info->start_time);
		if (philo->philo_info->who_died == 0)
			printf("%ld %d has taken a fork\n", diff_ms, philo->idx + 1);
		pthread_mutex_lock(&(philo->philo_info->mutex_fork[philo->idx]));
		diff_ms = get_time_diff_ms(philo->philo_info->start_time);
		if (philo->philo_info->who_died == 0)
			printf("%ld %d has taken a fork\n", diff_ms, philo->idx + 1);
	}
}

void	eating(t_philo *philo)
{
	int		right_philo;
	long	diff_ms;

	right_philo = right(philo->idx, philo->philo_info->num_philo);
	take_forks(philo);
	if (philo->philo_info->who_died == 1)
	{
		pthread_mutex_unlock(&(philo->philo_info->mutex_fork[philo->idx]));
		pthread_mutex_unlock(&(philo->philo_info->mutex_fork[right_philo]));
		return ;
	}
	diff_ms = get_time_diff_ms(philo->philo_info->start_time);
	gettimeofday(&(philo->last_ate_time), NULL);
	printf("%ld %d is eating\n", diff_ms, philo->idx + 1);
	my_msleep(philo->philo_info->time_to_eat);
	philo->ate_num += 1;
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
		if (philo->philo_info->who_died == 1 || \
		philo->ate_num >= philo->philo_info->num_of_must_eat)
			break ;
		sleeping(philo);
		usleep(100);
		if (philo->philo_info->who_died == 1)
			break ;
	}
}
