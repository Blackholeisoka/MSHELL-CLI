/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 23:51:29 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/14 23:51:29 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdio.h>
#include <unistd.h>

void	ft_tac_helper(char *file)
{
	int		i;
	char	arr[2000][1024];
	FILE	*f1;
	char	*r1;

	f1 = fopen(file, "r");
	i = 0;
	if (!f1)
	{
		ft_putstr("tac: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		return ;
	}
	ft_putstr("file: ");
	ft_putstr(file);
	ft_putstr("\n");
	while ((r1 = fgets(arr[i], sizeof(arr[i]), f1)))
		i++;
	i = i - 1;
	while (i >= 0)
		ft_putstr(arr[i--]);
	fclose(f1);
	ft_putstr("\n");
}

int	ft_tac(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "tac: missing file operand\n" RESET);
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
			ft_tac_helper(arr[i]);
	}
	else
	{
		ft_putstr(RED "tac: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
