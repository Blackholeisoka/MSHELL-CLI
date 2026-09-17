/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:08:45 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 01:08:45 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_kill(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_putstr(RED "kill: missing operand\n" RESET);
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
		{
			if (kill(ft_atoi(arr[i]), SIGTERM) == -1)
			{
				ft_putstr("kill: (");
				ft_putstr(arr[i]);
				ft_putstr("): No such process\n");
			}
		}
	}
	else
	{
		ft_putstr(RED "kill: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
