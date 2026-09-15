/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:13:25 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 00:13:25 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int	ft_mv(char **arr)
{
	char	path[1024];
	char	*dir;
	struct stat	st;

	if (arr_size(arr) == 1)
	{
			ft_putstr("mv: missing file operand\n");
	}
	else if (arr_size(arr) == 2)
	{
		ft_putstr("mv: missing destination file operand after '");
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
			if (rename(arr[i], path) != 0)
			{
				ft_putstr("mv: ");
				ft_putstr(arr[i]);
				ft_putstr(" no such file or directory\n");
			}
		}
	}
	else
	{
		ft_putstr("mv: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
