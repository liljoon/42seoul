/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/18 15:11:09 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"
# include<stdio.h>
static t_char_data	g_char_data;

void	sig_handler(int signo, siginfo_t *sig_info, void *p)
{
	p = (void *)p;
	g_char_data.c <<= 1;
	if (signo == SIGUSR1)
		;
	else if (signo == SIGUSR2)
		g_char_data.c |= 1;
	g_char_data.idx++;
	if (g_char_data.idx == 8)
	{
		if (g_char_data.c == 0)
		{
			write(1, "\n", 1);
			printf("pid : %d\n",sig_info->si_pid);
		}
		write(1, &(g_char_data.c), 1);
		g_char_data.c = 0;
		g_char_data.idx = 0;
	}
	return ;
}

int	main(void)
{
	pid_t				mypid;
	struct sigaction	sa;

	sa.sa_sigaction = (void *)sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	mypid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(mypid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
