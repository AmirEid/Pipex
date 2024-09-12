/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:04:17 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 14:51:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex.h"

int	initial_error(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	return (1);
}

void	error_message(char *str)
{
	perror(str);
	exit(1);
}
