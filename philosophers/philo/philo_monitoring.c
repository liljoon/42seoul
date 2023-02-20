/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:23:44 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/06 17:48:00 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	long		diff_ms;
	long		starving_time;

	diff_ms = get_time_diff_ms(philo->philo_info->start_time);
	starving_time = get_time_diff_ms(philo->last_ate_time);
	if (starving_time > philo->philo_info->time_to_die && \
	philo->ate_num < philo->philo_info->num_of_must_eat)
	{
		printf("%ld %d died\n", diff_ms, philo->idx + 1);
		philo->philo_info->who_died = 1;
		return ;
	}
}

void	monitoring(t_philo *philos)
{
	int	idx;
	int	cnt_done;

	while (1)
	{
		cnt_done = 0;
		idx = 0;
		while (idx < philos->philo_info->num_philo)
		{
			check_die(philos + idx);
			if (philos->philo_info->who_died == 1)
				return ;
			if (philos[idx].ate_num >= philos->philo_info->num_of_must_eat)
				cnt_done++;
			idx++;
		}
		if (cnt_done == philos->philo_info->num_philo)
			return ;
		usleep(1000);
	}
}
