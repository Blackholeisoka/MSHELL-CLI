/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:59:33 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/14 17:59:33 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdio.h>
#include <unistd.h>

void	ft_uniq_helper(char *file, int value)
{
	FILE	*f1;
	char	*r1;
	char	file_line[1024];
	char	file_line_before[1024];
	int		count;

	f1 = fopen(file, "r");
	file_line_before[0] = '\0';
	count = 1;
	if (!f1)
	{
		ft_putstr("uniq: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}
	ft_putstr(YELLOW "file: " RESET);
	ft_putstr(file);
	ft_putstr("\n");
	if (value == 0)
	{
		while ((r1 = fgets(file_line, sizeof(file_line), f1)))
		{
			if (ft_strcmp(file_line_before, file_line) && value == 0)
				ft_putstr(file_line);
			ft_strcpy(file_line_before, file_line);
		}
	}
	else
	{
		while ((r1 = fgets(file_line, sizeof(file_line), f1)))
		{
			if (ft_strcmp(file_line_before, file_line) == 0)
				count++;
			else
			{
				if ((value == 1 && count == 1) || (value == 2 && count > 1))
					ft_putstr(file_line_before);
				count = 1;
			}
			ft_strcpy(file_line_before, file_line);
		}
		if ((value == 1 && count == 1) || (value == 2 && count > 1))
			ft_putstr(file_line_before);
	}
	fclose(f1);
	ft_putstr("\n");
}

int	ft_uniq(char **arr)
{
	int	is_valid;
	int	value;
	int	start;

	value = 0;
	start = 1;
	if (arr_size(arr) == 1 || (arr_size(arr) == 2 && arr[1][0] == '-'))
	{
		ft_putstr(RED "uniq: missing file operand\n" RESET);
		return (0);
	}
	is_valid = (ft_strcmp(arr[1], "-d") == 0 || ft_strcmp(arr[1], "-u") == 0
			|| arr[1][0] != '-');
	if (arr_size(arr) >= 2 && is_valid)
	{
		if (ft_strcmp(arr[1], "-d") == 0)
		{
			value = 2;
			start = 2;
		}
		else if (ft_strcmp(arr[1], "-u") == 0)
		{
			start = 2;
			value = 1;
		}
		for (int i = start; arr[i] != NULL; i++)
			ft_uniq_helper(arr[i], value);
	}
	else
	{
		ft_putstr(RED "uniq: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
