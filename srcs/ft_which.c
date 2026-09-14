/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:40:14 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 15:40:14 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_which(char **arr)
{
	char	**path;
	char	program[1024];
	int	is_valid;

	if (arr_size(arr) == 1)
	{
		ft_putstr("which: missing argument\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		path = ft_split(getenv("PATH"), ":");
		for (int i = 1; arr[i] != NULL; i++)		
		{
			is_valid = 0;
			for (int j = 0; path[j] != NULL && !is_valid; j++)
			{
				snprintf(program, sizeof(program), "%s/%s", path[j], arr[i]);
				if (access(program, X_OK) == 0)
					is_valid = 1;
			}
			if (is_valid)
			{
				ft_putstr(program);
				ft_putstr("\n");
			}
			else
			{
				ft_putstr("which: ");
				ft_putstr(arr[i]);
				ft_putstr(": not found\n");
			}
				
		}
	}
	else
	{
		ft_putstr("which: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
