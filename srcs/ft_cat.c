/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 22:08:54 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/05 22:08:54 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <dirent.h>
#include <unistd.h>

int	ft_print_file_extension(char **arr)
{
	DIR				*dir;
	struct dirent	*e;
	char			*str;
	int				same;
	int i, j;

	dir = opendir(".");
	same = 0, i = 0, j = 0;
	while ((e = readdir(dir)))
	{
		str = e->d_name;
		same = 0, i = 0, j = 1;
		while ((str[i] != '\0') && (str[i] != '.'))
			i++;
		while (str[i] != '\0' && arr[1][j] != '\0')
		{
			if (str[i] != arr[1][j])
				same = 1;
			i++;
			j++;
		}
		if (same == 0 && str[i] == arr[1][j])
		{
			ft_putstr(str);
			ft_putstr(": ------------\n");
			ft_putstr("\n");
			ft_print_file(str);
			ft_putstr("\n");
		}
	}
	closedir(dir);
	return (0);
}

int	ft_cat(char **arr)
{
	DIR				*dir;
	struct dirent	*e;
	int				size;

	size = arr_size(arr);
	if (size == 1)
	{
		ft_putstr(RED "cat: missing file operand\n" RESET);
		return (1);
	}
	else if ((size == 2) && (arr[1][0] == '*'))
	{
		dir = opendir(".");
		while ((e = readdir(dir)))
		{
			if (arr[1][1] == '\0')
				ft_print_file(e->d_name);
			else
			{
				closedir(dir);
				ft_print_file_extension(arr);
				return (0);
			}
		}
		closedir(dir);
	}
	else if (size > 1)
	{
		for (int i = 1; i < size; i++)
		{
			if (arr[i][0] == '-')
			{
				ft_putstr(RED "cat: bad option: " RESET);
				ft_putstr(arr[i]);
				ft_putstr("\n");
				return (1);
			}
		}
		for (int i = 1; i < size; i++)
		{
			if (access(arr[i], F_OK) == 0)
			{
				ft_putstr(arr[i]);
				ft_putstr(": ------------\n");
				ft_putstr("\n");
				ft_print_file(arr[i]);
				ft_putstr("\n");
			}
		}
	}
	return (0);
}
