/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:47:04 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 21:47:04 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_yes(char **arr)
{
	int	i;

	if (arr_size(arr) == 1)
	{
		while (TRUE)
			ft_putstr("y\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		while (TRUE)
		{
			i = 1;
			while (arr[i] != NULL)
			{
				ft_putstr(arr[i]);
				ft_putstr(" ");
				i++;
			}
			ft_putstr("\n");
		}
	}
	else
	{
		ft_putstr(RED "yes: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
