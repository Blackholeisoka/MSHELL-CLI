/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:20:17 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 20:20:17 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_rmdir(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "rmdir: no such directory\n" RESET);
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; i < arr_size(arr); i++)
		{
			if (rmdir(arr[i]) == -1)
			{
				ft_putstr(RED "rmdir: cannot remove'" RESET);
				ft_putstr(arr[i]);
				ft_putstr("': Permission denied\n");
			}
		}
	}
	else
	{
		ft_putstr(RED "rmdir: bad option: \n" RESET);
		ft_putstr(arr[1]);
	}
	return (0);
}
