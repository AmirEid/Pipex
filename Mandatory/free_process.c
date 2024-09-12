/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:44:17 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 17:58:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex.h"

void	free_parent_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
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
	i = 0;
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->cmd_args);
	free(pipex->cmd);
}
