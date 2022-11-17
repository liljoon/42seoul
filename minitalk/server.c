/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/17 15:55:25 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
# include <stdio.h>

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		write(1, "0", 1);
	}
	else if (signo == SIGUSR2)
	{
		write(1, "1", 1);
	}
	return ;
}

int	main(void)
{
	pid_t	mypid;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	mypid = getpid();
	printf("PID : %d\n", mypid);
	while (1)
		pause();
	return (0);
}
