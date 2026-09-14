/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:27:17 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 16:27:17 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr_rev(char *str)
{
	for (int i = ft_strlen(str) - 1; i >= 0; i--)
		write(1, &str[i], 1);
}

void	ft_rev_helper(char *file)
{
	FILE *f1;
	char *r1;
	char	file_line[1024];

	f1 = fopen(file, "r");
	if (!f1)
	{
		ft_putstr("rev: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}

	while (TRUE)
	{
		file_line[0] = '\0';
		r1 = fgets(file_line, sizeof(file_line), f1);
		if (!r1) break ;
		if (file_line[ft_strlen(file_line) - 1] == '\n')
			file_line[ft_strlen(file_line) - 1] = '\0';
		ft_putstr_rev(file_line);
		ft_putstr("\n");
	}
	fclose(f1);
	ft_putstr("\n");
}

int	ft_rev(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr("rev: missing argument\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
		{
			ft_putstr("file: ");
			ft_putstr(arr[i]);
			ft_putstr("\n");
			ft_rev_helper(arr[i]);
		}
	}
	else
	{
		ft_putstr("rev: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
