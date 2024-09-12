/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:59:31 by aeid              #+#    #+#             */
/*   Updated: 2024/01/22 15:33:17 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

void	check_args(char **argv, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			error(ERROR_ARGS);
		i++;
	}
	if (argv && ft_strncmp("here_doc", argv[1], 8) == 0)
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
}

void	here_doc(char *av, t_pipex *pipex)
{
	int		fd;
	char	*buffer;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		error(ERROR_HEREDOC);
	while (pipex->here_doc)
	{
		buffer = get_next_line(0);
		if (buffer == NULL)
			exit(2);
		if (ft_strncmp(av, buffer, ft_strlen(av) - 1) == 0)
			break ;
		write(fd, buffer, ft_strlen(buffer));
		free(buffer);
	}
	get_next_line(-1);
	free(buffer);
	close(fd);
	pipex->input = open(".heredoc_tmp", O_RDONLY);
	if (pipex->input == -1)
	{
		unlink(".heredoc_tmp");
		error(ERROR_HEREDOC);
	}
}
