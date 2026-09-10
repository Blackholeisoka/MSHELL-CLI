/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 00:15:59 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/10 00:15:59 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>

void	ft_diff_compare_display(char *file_1, char *file_2)
{

	FILE *f1;
	FILE *f2;
	char	f1_line[1024];
	char	f2_line[1024];
	char	*r1;
	char	*r2;
	int	count_diff;
	int	count_line;

	f1 = fopen(file_1, "r");
	f2 = fopen(file_2, "r");
	
	if (!f1 || !f2)
	{
		ft_putstr("diff: cannot open file\n");
		if (f1)
			fclose(f1);
		if (f2)
			fclose(f2);
		return ;
	}
	count_diff = 1;
	count_line = 1;
	while (TRUE)
	{
		f1_line[0] = '\0';
		f2_line[0] = '\0';
		r1 = fgets(f1_line, sizeof(f1_line), f1);
		r2 = fgets(f2_line, sizeof(f2_line), f2);
		if (!r1 && !r2)
			break ;
		if (!r1 || !r2 || ft_strcmp(f1_line, f2_line) != 0)
		{
			ft_putstr("diff: ");
			ft_putnbr(count_diff);
			ft_putstr("\n");

			ft_putstr("<< ");
			ft_putstr(file_1);
			if (r1)
			{
				ft_putstr(" - l.");
				ft_putnbr(count_line);
			}
			else
				ft_putstr("END");
			ft_putstr("\n");
			ft_putstr(f1_line);

			ft_putstr("-----");
			ft_putstr("\n");

			ft_putstr(">> ");
			ft_putstr(file_2);
			if (r2)
			{
				ft_putstr(" - l.");
				ft_putnbr(count_line);
			}
			else
				ft_putstr("END");
			ft_putstr("\n");
			ft_putstr(f2_line);
			ft_putstr("\n");
			count_diff++;
		}
		count_line++;
	}
	fclose(f1);
	fclose(f2);
}

int	ft_diff(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr("diff: missing argument\n");
	}
	else if (arr_size(arr) == 2)
	{
		if (arr[1][0] == '-')
		{
			ft_putstr("diff: bad option: ");
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("diff: missing operand after '");
			ft_putstr(arr[1]);
			ft_putstr("'\n");
		}
	}
	else if (arr_size(arr) == 3)
	{
		ft_diff_compare_display(arr[1], arr[2]);
	}
	else
	{
		ft_putstr("diff: too many arguments\n");
	}
	return (0);
}
