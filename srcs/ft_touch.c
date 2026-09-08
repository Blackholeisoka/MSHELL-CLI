/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:45:37 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 19:45:37 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_touch(char **arr)
{
	if (arr_size(arr) ==  1)
	{
			ft_putstr("touch: no such file or directory\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; i < arr_size(arr); i++)
		{
			int	fd;

			fd = open(arr[i], O_CREAT | O_WRONLY, 0644);
			if (fd < 0)
			{
				ft_putstr("touch: cannot touch '");
				ft_putstr(arr[i]);
				ft_putstr("': Permission denied\n");
			}
			close(fd);
		}
	}
	else
	{
		ft_putstr("touch: bad option: \n");
		ft_putstr(arr[1]);
	}
	return (0);
}
