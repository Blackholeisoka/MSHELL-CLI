/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:20:11 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 20:20:11 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_rm(char **arr)
{
	if (arr_size(arr) ==  1)
	{
			ft_putstr("rm: no such file\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; i < arr_size(arr); i++)
		{
			if (unlink(arr[i]) == -1)
			{
				ft_putstr("rm: cannot remove'");
				ft_putstr(arr[i]);
				ft_putstr("': Permission denied\n");
			}
		}
	}
	else
	{
		ft_putstr("rm: bad option: \n");
		ft_putstr(arr[1]);
	}
	return (0);
}
