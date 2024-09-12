/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:10:23 by aeid              #+#    #+#             */
/*   Updated: 2024/01/20 16:56:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5 || *argv[1] == '\0' || *argv[2] == '\0' || *argv[3] == '\0')
		return (initial_error(ERROR_ARGS));
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		error_message(ERROR_INPUT);
	pipex.output = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.output == -1)
		error_message(ERROR_OUTPUT);
	if (pipe(pipex.fd) == -1)
		error_message(ERROR_FORK);
	pipex.path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_kid(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_kid(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent_process(&pipex);
	return (0);
}
