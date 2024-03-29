/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/18 14:12:14 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

static t_char_data	g_char_data;

void	sig_handler(int signo)
{
	g_char_data.c <<= 1;
	if (signo == SIGUSR1)
		;
	else if (signo == SIGUSR2)
		g_char_data.c |= 1;
	g_char_data.idx++;
	if (g_char_data.idx == 8)
	{
		if (g_char_data.c == 0)
			write(1, "\n", 1);
		write(1, &(g_char_data.c), 1);
		g_char_data.c = 0;
		g_char_data.idx = 0;
	}
	return ;
}

int	main(void)
{
	pid_t	mypid;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	mypid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(mypid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
