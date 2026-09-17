/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:33:45 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/10 21:33:45 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdio.h>
#include <unistd.h>

int	ft_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
int	ft_wc_count(char *str)
{
	int	count;

	count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!ft_space(str[i]) && (i == 0 || ft_space(str[i - 1])))
			count++;
	}
	return (count);
}
int	ft_wc_helper(char *file, int value)
{
	FILE	*f1;
	char	*r1;
	int		count;
	int		count_word;
	int		count_line;
	char	file_line[1024];

	count = 0;
	count_word = 0;
	count_line = 0;
	f1 = fopen(file, "r");
	if (!f1)
	{
		ft_putstr("wc: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return (-1);
	}
	while (TRUE)
	{
		file_line[0] = '\0';
		r1 = fgets(file_line, sizeof(file_line), f1);
		if (!r1)
			break ;
		count += ft_strlen(file_line);
		count_word += ft_wc_count(file_line);
		count_line++;
	}
	fclose(f1);
	if (value == 0)
		return (count_word);
	else if (value == 1)
		return (count);
	else
		return (count_line);
}

int	ft_wc(char **arr)
{
	int	is_valid_param;
	int	value;
	int	start;
	int	result;

	value = 0;
	start = 1;
	result = 0;
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "wc: missing file operand\n" RESET);
		return (0);
	}
	is_valid_param = (ft_strcmp(arr[1], "-l") == 0 || ft_strcmp(arr[1],
				"-c") == 0);
	if (arr_size(arr) >= 2 && (is_valid_param || arr[1][0] != '-'))
	{
		if (ft_strcmp(arr[1], "-l") == 0)
		{
			value = 2;
			start = 2;
		}
		if (ft_strcmp(arr[1], "-c") == 0)
		{
			value = 1;
			start = 2;
		}
		for (int i = start; arr[i] != NULL; i++)
		{
			result = ft_wc_helper(arr[i], value);
			if (result >= 0)
			{
				ft_putstr(arr[i]);
				ft_putstr(": ");
				ft_putnbr(result);
				ft_putstr("\n");
			}
		}
	}
	else
	{
		ft_putstr(RED "wc: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
