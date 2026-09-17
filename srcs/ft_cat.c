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
#include <fcntl.h>

void	ft_print_file_raw(char *str)
{
	int		fd;
	int		n;
	char	buff[1024];

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return ;
	while ((n = read(fd, buff, sizeof(buff))) > 0)
		write(1, buff, n);
	close(fd);
}

int	ft_print_file_extension(char **arr)
{
	DIR				*dir;
	struct dirent	*e;
	char			*str;
	int				same;
	int				i;
	int				j;

	dir = opendir(".");
	while ((e = readdir(dir)))
	{
		str = e->d_name;
		same = 0;
		i = 0;
		j = 1;
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
			ft_putstr(YELLOW "file: " RESET);
			ft_putstr(str);
			ft_putstr("\n");
			ft_print_file_raw(str);
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
	int				i;

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
				ft_print_file_raw(e->d_name);
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
		i = 1;
		while (i < size)
		{
			if (arr[i][0] == '-')
			{
				ft_putstr(RED "cat: bad option: " RESET);
				ft_putstr(arr[i]);
				ft_putstr("\n");
				return (1);
			}
			i++;
		}
		i = 1;
		while (i < size)
		{
			if (access(arr[i], F_OK) == 0)
			{
				ft_putstr(YELLOW "file: " RESET);
				ft_putstr(arr[i]);
				ft_putstr("\n");
				ft_print_file_raw(arr[i]);
				ft_putstr("\n");
			}
			i++;
		}
	}
	return (0);
}
