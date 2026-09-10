/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:25:56 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/10 23:25:56 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>

void	ft_head_helper(char *file, int size)
{
	FILE *f1;
	char *r1;
	char	file_line[1024];
	int	count;

	f1 = fopen(file, "r");
	count = 0;
	if (!f1)
	{
		ft_putstr("head: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}

	while (count < size)
	{
		file_line[0] = '\0';
		r1 = fgets(file_line, sizeof(file_line), f1);
		if (!r1) break ;
		ft_putstr(file_line);
		count++;
	}
	fclose(f1);
	ft_putstr("\n");
}

int	ft_head(char **arr)
{
	int	is_valid_param;
	int	size;
	int	start;

	size = 10;
	start = 0;
	if (arr_size(arr) == 1)
	{
		ft_putstr("head: missing file operand\n");
		return (0);
	}
	is_valid_param = (ft_strcmp(arr[1], "-n") == 0 || arr[1][0] != '-');
	if(arr_size(arr) >= 2 && is_valid_param)
	{
		start = 1;
		if (ft_strcmp(arr[1], "-n") == 0)
		{
			if (!arr[2] || ft_atoi(arr[2]) <= 0)
			{
				ft_putstr("head: invalid number of lines\n");
				return (1);
			}
			size = ft_atoi(arr[2]);
			start = 3;
		}
		for (int i = start; arr[i] != NULL; i++)
		{
			ft_putstr("file: ");
			ft_putstr(arr[i]);
			ft_putstr("\n");
			ft_head_helper(arr[i], size);
		}
	}
	else
	{
		ft_putstr("head: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
