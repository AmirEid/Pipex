/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:59:19 by aeid              #+#    #+#             */
/*   Updated: 2024/01/20 16:46:01 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex.h"

static char	*get_command(char **paths, char *cmd)
{
	char	*p;
	char	*command;

	while (*paths)
	{
		p = ft_strjoin(*paths, "/");
		command = ft_strjoin(p, cmd);
		free(p);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_kid(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	dup2(pipex.input, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_process(&pipex);
		initial_error(ERROR_CMD);
		exit(2);
	}
	close (pipex.fd[1]);
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_kid(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	dup2(pipex.output, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_process(&pipex);
		initial_error(ERROR_CMD);
		exit(3);
	}
	close (pipex.fd[0]);
	execve(pipex.cmd, pipex.cmd_args, envp);
}
