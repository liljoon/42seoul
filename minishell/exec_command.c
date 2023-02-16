/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:36:25 by isunwoo           #+#    #+#             */
/*   Updated: 2023/02/16 15:32:09 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_path(char *argv[], char *envp[])
{
	char	*path;
	char	**paths;
	char	*old_argv0;


	if (argv[0][0] == '/')
		execve(argv[0], argv, envp);
	else
	{
		old_argv0 = argv[0];
		path = getenv("PATH");
		paths = ft_split(path, ':');
		while (*paths)
		{
			argv[0] = old_argv0;
			argv[0] = ft_strjoin("/", argv[0]);
			argv[0] = ft_strjoin(*paths, argv[0]);
			execve(argv[0], argv, envp);
			paths++;
		}
	}
}

void	exec_command(char *command, char *envp[])
{
	pid_t	pid;
	char	**argv;

	pid = fork();
	if (pid == 0)
	{
		argv = ft_split(command, ' ');
		if (*argv == NULL)
			exit(0);
		check_path(argv, envp);
		//printf("minishell: %s: %s\n", argv[0], strerror(errno));
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return ;
}
