/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 23:07:19 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/09 23:07:19 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_env(char **arr)
{
	extern char	**environ;

	if (arr_size(arr) == 1)
	{
		for (int i = 0; environ[i] != NULL; i++)
		{
			ft_putstr(environ[i]);
			ft_putstr("\n");
		}
		ft_putstr("\n");
	}
	else
	{
		if (arr[1][0] == '-')
		{
			ft_putstr(RED "env: bad option: " RESET);
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("env: arguments not supported\n");
		}
	}
	return (0);
}
