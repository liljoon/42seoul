/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/17 18:29:21 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
# include <stdio.h>

typedef struct s_char_data
{
	int		idx;
	char	c;
}	t_char_data;

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
	printf("PID : %d\n", mypid);
	while (1)
		pause();
	return (0);
}
