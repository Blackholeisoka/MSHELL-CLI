/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 23:34:18 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/09 23:34:18 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_have_equal(char **arr)
{
	for (int i = 0; arr[i] != NULL; i++)
		for (int j = 0; arr[i][j] != '\0'; j++)
			if(arr[i][j] == '=')
				return (1);
	return (0);
}

int	ft_export(char **arr)
{
	char	**env_export;
	if (arr_size(arr) == 1)
	{
		ft_putstr("export: missing argument\n");
	}
	else
	{
		if (arr[1][0] == '-')
		{
			ft_putstr("export: bad option: ");
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
		else
		{
			for (int i = 1; arr[i] != NULL; i++)
			{
				env_export = ft_split(arr[i], "=");
				if (!ft_have_equal(env_export) || setenv(env_export[0], env_export[1], 1) == -1)
				{
					ft_putstr("export: cannot set '");
					ft_putstr(env_export[0]);
					ft_putstr("'\n");
					return (1);
				}
				setenv(env_export[0], env_export[1], 1);
			}
		}
	}
	return (0);
}
