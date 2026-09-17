/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:35:23 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 17:35:23 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

void	ft_basename_helper(char *dir)
{
	int	max;

	max = -1;
	for (int i = 0; dir[i] != '\0'; i++)
		if (dir[i] == '/' && dir[i + 1] != '\0')
			max = i;
	for (int i = (max + 1); dir[i] != '\0'; i++)
		write(1, &dir[i], 1);
	ft_putstr("\n");
}

int	ft_basename(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "basename: missing operand\n" RESET);
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
			ft_basename_helper(arr[i]);
	}
	else
	{
		ft_putstr(RED "basename: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
