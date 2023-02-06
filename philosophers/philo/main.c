/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:42:03 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/05 21:40:55 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_info(int argc, char *argv[], t_philo_info *philo_info)
{
	int	idx;

	if (!(argc == 5 || argc == 6))
		return (-1);
	philo_info->num_philo = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->num_of_must_eat = ft_atoi(argv[5]);
	else
		philo_info->num_of_must_eat = -1;
	philo_info->mutex_fork = \
		malloc(sizeof(pthread_mutex_t) * philo_info->num_philo);
	idx = 0;
	while (idx < philo_info->num_philo)
	{
		pthread_mutex_init(philo_info->mutex_fork + idx, NULL);
		idx++;
	}
	philo_info->who_died = 0;
	return (0);
}

t_philo	*init_philo(t_philo_info *philo_info)
{
	t_philo	*ret;
	int		idx;

	ret = malloc(sizeof(t_philo) * philo_info->num_philo);
	idx = 0;
	while (idx < philo_info->num_philo)
	{
		ret[idx].idx = idx;
		ret[idx].philo_info = philo_info;
		ret[idx].state = 1;
		ret[idx].ate_num = 0;
		idx++;
	}
	return (ret);
}

void	free_all(t_philo_info *philo_info, t_philo *philos)
{
	int	idx;

	idx = 0;
	while (idx < philo_info->num_philo)
	{
		pthread_mutex_destroy(philo_info->mutex_fork + idx);
		idx++;
	}
	free(philos);
	free(philo_info->mutex_fork);
}

int	main(int argc, char *argv[])
{
	t_philo_info	philo_info;
	t_philo			*philos;

	if (init_philo_info(argc, argv, &philo_info) == -1)
		return (1);
	philos = init_philo(&philo_info);
	start_philo(philos);
	free_all(&philo_info, philos);
}
