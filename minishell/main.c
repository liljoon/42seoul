/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:01:17 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/16 13:36:54 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;

	set_signal();
	while (1)
	{
		command = readline("minishell$ ");
		if (!command)
		{
			printf("\033[1A");
			printf("\033[11C");
			printf("exit\n");
			exit(0);
		}
		if (command && *command)
			add_history(command);
		exec_command(command, envp);
		free(command);
	}
}
