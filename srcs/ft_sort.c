/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:28:25 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 21:28:25 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdio.h>
#include <unistd.h>

void	ft_sort_arr(char arr[][1024], int value, int count)
{
	int		i;
	int		change;
	char	temp[1024];

	change = 1;
	while (change)
	{
		change = 0;
		i = 0;
		while (i < count - 1)
		{
			if ((value == 0 && ft_strcmp(arr[i], arr[i + 1]) > 0) || (value == 1
					&& ft_strcmp(arr[i], arr[i + 1]) < 0))
			{
				ft_strcpy(temp, arr[i]);
				ft_strcpy(arr[i], arr[i + 1]);
				ft_strcpy(arr[i + 1], temp);
				change = 1;
			}
			i++;
		}
	}
}

int	ft_sort_helper(char *file, int value)
{
	FILE	*f1;
	char	arr[2000][1024];
	int		count;
	int		i;

	count = 0;
	f1 = fopen(file, "r");
	if (!f1)
	{
		ft_putstr(file);
		ft_putstr(": no such file or directory\n");
		return (0);
	}
	while (fgets(arr[count], 1024, f1))
		count++;
	fclose(f1);
	ft_sort_arr(arr, value, count);
	i = 0;
	ft_putstr(file);
	ft_putstr(":\n");
	while (i < count)
		ft_putstr(arr[i++]);
	return (1);
}

int	ft_sort(char **arr)
{
	int	start;

	start = 1;
	if (arr_size(arr) == 1)
	{
		ft_putstr("no such file or directory\n");
	}
	else if (arr_size(arr) >= 2 && (ft_strcmp(arr[1], "-r") == 0
			|| arr[1][0] != '-'))
	{
		if (ft_strcmp(arr[1], "-r") == 0)
			start = 2;
		for (int i = start; arr[i] != NULL; i++)
			ft_sort_helper(arr[i], (start == 1 ? 0 : 1));
	}
	else
	{
		ft_putstr(RED "sort: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
