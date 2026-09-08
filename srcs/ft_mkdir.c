/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:16:07 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 20:16:07 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <sys/stat.h>

int	ft_mkdir(char **arr)
{
	if (arr_size(arr) ==  1)
	{
			ft_putstr("mkdir: no such file or directory\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; i < arr_size(arr); i++)
		{
			if (mkdir(arr[i], 0755) == -1)
			{
				ft_putstr("mkdir: cannot create'");
				ft_putstr(arr[i]);
				ft_putstr("': Permission denied\n");
			}
		}
	}
	else
	{
		ft_putstr("mkdir: bad option: \n");
		ft_putstr(arr[1]);
	}
	return (0);
}
