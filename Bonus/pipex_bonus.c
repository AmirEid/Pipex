/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:23:23 by aeid              #+#    #+#             */
/*   Updated: 2024/01/20 19:53:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->num_cmd_forks - 1))
	{
		if (pipe(pipex->pipes + 2 * i) == -1)
		{
			free_parent_process(pipex);
			error(ERROR_PIPE);
		}
		i++;
	}
}

void	close_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->num_pipes_idstring)
	{
		close(pipex->pipes[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (error_message(ERROR_ARGS));
	check_args(argv, &pipex);
	open_input(argv, &pipex);
	open_output(argv[argc - 1], &pipex);
	pipex.num_cmd_forks = argc - 3 - pipex.here_doc;
	pipex.num_pipes_idstring = (pipex.num_cmd_forks - 1) * 2;
	pipex.pipes = (int *)malloc(pipex.num_pipes_idstring * sizeof(int));
	if (!pipex.pipes)
		error(ERROR_MEM);
	pipex.path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	if (!pipex.cmd_paths)
		free_pipes(&pipex);
	create_pipes(&pipex);
	pipex.id = -1;
	while (++(pipex.id) < pipex.num_cmd_forks)
		create_kid(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(-1, NULL, 0);
	free_parent_process(&pipex);
	return (0);
}
