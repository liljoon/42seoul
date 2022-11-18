/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/18 14:35:28 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	char	*s;

	if (argc != 3)
		exit(1);
	s = argv[2];
	while (*s != '\0')
	{
		send_char(ft_atoi(argv[1]), *s);
		s++;
	}
	send_char(ft_atoi(argv[1]), 0);
	return (0);
}
