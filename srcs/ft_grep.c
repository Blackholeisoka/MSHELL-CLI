/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 22:56:57 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/11 22:56:57 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdio.h>
#include <unistd.h>

int	ft_strstr(char *str, char *file_line)
{
	int	i;
	int	j;
	int	str_length;

	i = 0;
	str_length = ft_strlen(str);
	while (file_line[i] != '\0')
	{
		j = 0;
		while (j < str_length && file_line[i + j] == str[j])
			j++;
		if (j == str_length)
			return (1);
		i++;
	}
	return (0);
}

void	ft_grep_helper(char *str, char *file, int value)
{
	FILE	*f1;
	char	*r1;
	char	file_line[1024];
	int		count_line;
	int		count;

	f1 = fopen(file, "r");
	count_line = 1;
	count = 0;
	if (!f1)
	{
		ft_putstr("grep: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}
	ft_putstr(YELLOW "file: " RESET);
	ft_putstr(file);
	ft_putstr("\n");
	while (TRUE)
	{
		file_line[0] = '\0';
		r1 = fgets(file_line, sizeof(file_line), f1);
		if (!r1)
			break ;
		if (value == 0)
		{
			if (ft_strstr(str, file_line))
			{
				ft_putstr(file_line);
				count++;
			}
		}
		else if (value == 1)
		{
			if (ft_strstr(str, file_line))
			{
				ft_putnbr(count_line);
				ft_putstr(". ");
				ft_putstr(file_line);
				count++;
			}
		}
		else
		{
			if (!ft_strstr(str, file_line))
			{
				ft_putstr(file_line);
				count++;
			}
		}
		count_line++;
	}
	if (count == 0)
		ft_putstr("grep: no match found\n");
	ft_putstr("\n");
	fclose(f1);
}

int	ft_grep(char **arr)
{
	int	valid_params;
	int	value;

	value = 0;
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "grep: missing pattern\n" RESET);
	}
	else if (arr_size(arr) == 2)
	{
		ft_putstr(RED "grep: missing file operand\n" RESET);
	}
	if (arr_size(arr) >= 3)
	{
		valid_params = (ft_strcmp(arr[1], "-n") == 0 || ft_strcmp(arr[1],
					"-v") == 0);
		if (valid_params)
		{
			value = (ft_strcmp(arr[1], "-n") == 0) ? 1 : 2;
			for (int i = 3; arr[i] != NULL; i++)
				ft_grep_helper(arr[2], arr[i], value);
		}
		else if (!valid_params && arr[1][0] != '-')
		{
			for (int i = 2; arr[i] != NULL; i++)
				ft_grep_helper(arr[1], arr[i], value);
		}
		else
		{
			ft_putstr(RED "grep: bad option: " RESET);
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
	}
	return (0);
}
