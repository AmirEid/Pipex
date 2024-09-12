/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:15:52 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 18:11:49 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex_bonus.h"

int	error_message(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	return (1);
}

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	error_command(char *cmd)
{
	write(2, ERROR_CMD, ft_strlen(ERROR_CMD));
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}
