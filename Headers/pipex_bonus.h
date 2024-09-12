/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:13:16 by aeid              #+#    #+#             */
/*   Updated: 2024/01/20 20:00:09 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Headers/get_next_line.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR_INPUT "Opening input failed"
# define ERROR_OUTPUT "Opening output failed"
# define ERROR_PIPE "Pipe returned -1"
# define ERROR_FORK "Fork process returned -1"
# define ERROR_CMD "The following command was not found: "
# define ERROR_ARGS "Invalid passed arguments.\n"
# define ERROR_MEM "Failed to allocate memory"
# define ERROR_HEREDOC "Failed to open heredoc file"
# define ERROR_ENVP "Environment path problem"

typedef struct s_pipex
{
	pid_t	pid;
	int		num_cmd_forks;
	int		*pipes;
	int		num_pipes_idstring;
	int		id;
	int		here_doc;
	int		input;
	int		output;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

int			error_message(char *str);
void		error(char *str);
void		open_input(char **argv, t_pipex *pipex);
void		open_output(char *argv, t_pipex *pipex);
char		**ft_split(char *str, char c);
void		free_parent_process(t_pipex *pipex);
void		check_args(char **argv, t_pipex *pipex);
size_t		ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		here_doc(char *av, t_pipex *pipex);
void		create_kid(t_pipex pipex, char **argv, char **envp);
void		close_pipe(t_pipex *pipex);
void		error_command(char *cmd);
void		free_child_process(t_pipex *pipex);
void		free_pipes(t_pipex *pipex);

#endif