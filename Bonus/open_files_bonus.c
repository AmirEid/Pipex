/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:38 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 14:50:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

void	open_input(char **argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		here_doc(argv[2], pipex);
	else
	{
		pipex->input = open(argv[1], O_RDONLY);
		if (pipex->input == -1)
			error(ERROR_INPUT);
	}
}

void	open_output(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->output = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->output = open(argv, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->output == -1)
		error(ERROR_OUTPUT);
}
