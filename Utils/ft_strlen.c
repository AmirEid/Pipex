/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:41 by aeid              #+#    #+#             */
/*   Updated: 2024/01/19 16:01:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/pipex.h"

//#include <stdio.h>//
//#include <string.h>//

size_t	ft_strlen(char *str)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

/*int main()
{
    //int i = ft_strlen ("hello");//
    int i = strlen("Hello");
    printf("the length of the array is %i", i);
    return (0);
}*/
