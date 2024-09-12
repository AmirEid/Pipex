/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:39:05 by aeid              #+#    #+#             */
/*   Updated: 2024/01/20 19:34:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
# define ERROR_CMD "command not found"
# define ERROR_ARGS "Invalid passed arguments.\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		input;
	int		output;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

int			initial_error(char *str);
void		free_parent_process(t_pipex *pipex);
void		free_child_process(t_pipex *pipex);
void		first_kid(t_pipex pipex, char **argv, char **envp);
void		second_kid(t_pipex pipex, char **argv, char **envp);
void		error_message(char *str);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *str, char c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
