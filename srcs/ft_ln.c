/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ln.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 20:59:19 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 20:59:19 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_ln(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr("ln: missing file operand\n");
	}
	else if (arr_size(arr) == 2)
	{
		ft_putstr("ln: missing destination file operand after '");
		ft_putstr(arr[1]);
		ft_putstr("'\n");
	}
	else if (arr_size(arr) == 3 && arr[1][0] != '-')
	{
		if (link(arr[1], arr[2]) == -1)
		{
			ft_putstr("ln: failed to create hard link '");
			ft_putstr(arr[2]);
			ft_putstr("': File exists\n");
		}
	}
	else if (arr_size(arr) == 4 && ft_strcmp(arr[1], "-s") == 0)
	{
		if (symlink(arr[2], arr[3]) == -1)
		{
			ft_putstr("ln: failed to create symbolic link '");
			ft_putstr(arr[3]);
			ft_putstr("': File exists\n");
			return (1);
		}
	}
	else if (arr_size(arr) > 4 && arr[1][0] != '-')
	{
		ft_putstr("ln: too many arguments\n");
	}
	else
	{
		ft_putstr("ln: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
