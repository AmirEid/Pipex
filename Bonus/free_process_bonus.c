/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:00:19 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 18:01:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

void	free_parent_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->pipes);
}

void	free_child_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
	i = 0;
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->pipes);
}

void	free_pipes(t_pipex *pipex)
{
	close(pipex->input);
	close(pipex->output);
	free(pipex->pipes);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	error_message(ERROR_ENVP);
	exit(4);
}
