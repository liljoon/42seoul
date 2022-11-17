/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:39:28 by isunwoo           #+#    #+#             */
/*   Updated: 2022/11/17 15:59:25 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
# include<stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		exit(1);
	if (atoi(argv[2]) == 0)
		kill(atoi(argv[1]), SIGUSR1);
	if (atoi(argv[2]) == 1)
		kill(atoi(argv[1]), SIGUSR2);
	return (0);
}
