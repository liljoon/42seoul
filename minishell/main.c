/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:01:17 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/14 22:53:02 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(char *command, char *envp[])
{
	pid_t	pid;

	pid = fork();
	char *argv[]   = { "/bin/ls", NULL};
	if (pid == 0)
	{
		execve("/bin/ls", argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return ;
}

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
		//printf("%s\n", command);
		if (command && *command)
			add_history(command);
		exec_command(command, envp);
		free(command);
	}
}
