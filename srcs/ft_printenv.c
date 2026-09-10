/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 23:19:34 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/09 23:19:34 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_printenv(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr("printenv: missing argument\n");
	}
	else
	{
		if (arr[1][0] == '-')
		{
			ft_putstr("printenv: bad option: ");
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
		else
		{
			for (int i = 1; arr[i] != NULL; i++)
			{
				if (getenv(arr[i]))
				{
					ft_putstr(getenv(arr[i]));
					ft_putstr("\n");
				}
			}
			ft_putstr("\n");
		}
	}
	return (0);
}
