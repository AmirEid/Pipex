/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:48:24 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 18:20:09 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

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

static void	dup_dup(int x, int y)
{
	dup2(x, 0);
	dup2(y, 1);
}

void	create_kid(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (pipex.pid == -1)
		error(ERROR_FORK);
	if (pipex.pid == 0)
	{
		if (pipex.id == 0)
			dup_dup(pipex.input, pipex.pipes[1]);
		else if (pipex.id == pipex.num_cmd_forks - 1)
			dup_dup(pipex.pipes[(pipex.id * 2) - 2], pipex.output);
		else
			dup_dup(pipex.pipes[(pipex.id * 2) - 2], pipex.pipes[(pipex.id * 2)
				+ 1]);
		pipex.cmd_args = ft_split(argv[2 + pipex.here_doc + pipex.id], ' ');
		pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
		if (!pipex.cmd)
		{
			error_command(pipex.cmd_args[0]);
			free_child_process(&pipex);
			exit(3);
		}
		close_pipe(&pipex);
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
}
