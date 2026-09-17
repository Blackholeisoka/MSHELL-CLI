/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 00:42:24 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/05 00:42:24 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_cd(char **arr)
{
	char	*str;

	if (arr_size(arr) < 3)
	{
		if (arr_size(arr) == 1)
			str = getenv("HOME");
		else
			str = arr[1];
		if (!str || chdir(str) != 0)
			ft_putstr("no such file or directory\n");
	}
	else
	{
		ft_putstr(RED "cd: bad option: " RESET);
		ft_putstr(arr[2]);
		ft_putstr("\n");
	}
	return (0);
}
