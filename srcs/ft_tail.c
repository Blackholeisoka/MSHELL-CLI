/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:25:51 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/10 23:25:51 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>

void	ft_tail_helper(char *file, int size)
{
	FILE *f1;
	char *r1;
	char	file_line[1024];
	int	count;
	int	file_size;

	f1 = fopen(file, "r");
	count = 0;
	file_size = ft_file_count_line(file);
	if (!f1)
	{
		ft_putstr("tail: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}

	while (TRUE)
	{
		file_line[0] = '\0';
		r1 = fgets(file_line, sizeof(file_line), f1);
		if (!r1) break ;
		if (count >= (file_size - size))
			ft_putstr(file_line);
		count++;
	}
	fclose(f1);
	ft_putstr("\n");
}

int	ft_tail(char **arr)
{
	int	is_valid_param;
	int	size;
	int	start;

	size = 10;
	start = 0;
	if (arr_size(arr) == 1)
	{
		ft_putstr("tail: missing file operand\n");
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
				ft_putstr("tail: invalid number of lines\n");
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
			ft_tail_helper(arr[i], size);
		}
	}
	else
	{
		ft_putstr("tail: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
