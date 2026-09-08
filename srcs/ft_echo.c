/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:55:07 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/07 22:55:07 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_echo(char **arr)
{
	int	i;

	if (arr_size(arr) == 1)
	{
		ft_putstr("\n");
		return (0);
	}
	else if (arr[1][0] == '-' && arr[1][1] == 'n' && arr[1][2] == '\0')
	{
		i = 2;
		while (i < arr_size(arr))
		{
			ft_putstr(arr[i]);
			ft_putstr("%");
			if (i + 1 < arr_size(arr))
				ft_putstr(" ");
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
	else if (arr[1][0] == '-')
	{
		ft_putstr("echo: bad option: ");
		ft_putstr(arr[1]);
	}
	else
	{
		i = 1;
		while (i < arr_size(arr))
		{
			ft_putstr(arr[i]);
			if (i + 1 < arr_size(arr))
				ft_putstr(" ");
			i++;
		}
	}
	ft_putstr("\n");
	return (0);
}
