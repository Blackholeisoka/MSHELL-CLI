/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:35:28 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 17:35:28 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_dirname_helper(char *dir)
{
	int	count_slash;
	int	max;
	
	count_slash = 0;
	max = 0;
	for (int i = 0; dir[i] != '\0'; i++)
	{
		if (dir[i] == '/' && dir[i + 1] != '\0')
		{
			count_slash++;
			max = i;
		}
	}
	if (count_slash == 0)
		ft_putstr(".");
	else if (count_slash == 1 && dir[0] == '/')
		ft_putstr("/");
	else
	{
		for (int j = 0; j < max; j++)
			write(1, &dir[j], 1);
	}
	ft_putstr("\n");
}

int	ft_dirname(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr("dirname: missing operand\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
			ft_dirname_helper(arr[i]);
	}
	else
	{
		ft_putstr("dirname: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
