/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:49:26 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/03 01:48:50 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->idx);
	usleep(philo->philo_info->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->idx);
}

void	eating(t_philo *philo)
{
	int	right_philo;

	right_philo = right(philo->idx, philo->philo_info->num_philo);
	pthread_mutex_lock(&(philo->philo_info->mutex_fork[philo->idx]));
	pthread_mutex_lock(&(philo->philo_info->mutex_fork[right_philo]));
	printf("%d is eating\n", philo->idx);
	usleep(philo->philo_info->time_to_eat * 1000);
	pthread_mutex_unlock(&(philo->philo_info->mutex_fork[philo->idx]));
	pthread_mutex_unlock(&(philo->philo_info->mutex_fork[right_philo]));
}

void	philosopher(t_philo *philo)
{
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
}

void	start_philo(t_philo *philos)
{
	int			idx;
	pthread_t	*thread;

	thread = malloc(sizeof(thread) * philos->philo_info->num_philo);
	idx = 0;
	while (idx < philos->philo_info->num_philo)
	{
		pthread_create(thread + idx, NULL, (void *)philosopher, philos + idx);
		idx++;
	}
	idx = 0;
	while (idx < philos->philo_info->num_philo)
	{
		pthread_join(thread[idx], NULL);
		idx++;
	}
}
