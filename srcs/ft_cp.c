/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:40:49 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 00:40:49 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int	ft_cp_helper(char *file_src, char *path)
{
	int		f1;
	int		f2;
	int		n;
	char	file_src_line[1024];

	f1 = open(file_src, O_RDONLY);
	f2 = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	n = 0;
	if (f1 < 0 || f2 < 0)
		return (0);
	while ((n = read(f1, file_src_line, sizeof(file_src_line))) > 0)
		write(f2, file_src_line, n);
	close(f1);
	close(f2);
	return (1);
}

int	ft_cp(char **arr)
{
	char		path[1024];
	char		*dir;
	struct stat	st;

	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "cp: missing file operand\n" RESET);
	}
	else if (arr_size(arr) == 2)
	{
		ft_putstr(RED "cp: missing destination file operand after '" RESET);
		ft_putstr(arr[1]);
		ft_putstr("'\n");
	}
	else if (arr_size(arr) >= 3 && arr[1][0] != '-')
	{
		dir = arr[arr_size(arr) - 1];
		for (int i = 1; i < arr_size(arr) - 1; i++)
		{
			if (stat(dir, &st) == 0 && S_ISDIR(st.st_mode))
				snprintf(path, sizeof(path), "%s/%s", dir, arr[i]);
			else
				snprintf(path, sizeof(path), "%s", dir);
			if (!ft_cp_helper(arr[i], path))
			{
				ft_putstr("cp: ");
				ft_putstr(arr[i]);
				ft_putstr(" no such file or directory\n");
			}
		}
	}
	else
	{
		ft_putstr(RED "cp: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
