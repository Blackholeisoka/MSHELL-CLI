/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:08:24 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/11 21:08:24 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_history(char **arr)
{
	char	path_file[1024];

	snprintf(path_file, sizeof(path_file), "%s/.history", getenv("HOME"));
	if (arr_size(arr) == 1)
	{	
		if (access(path_file, F_OK) == 0)
		{
			ft_print_file(path_file);
			ft_putstr("\n");
		}
		else
		{
		ft_putstr("history: No such file or directory\n");
		}
	}
	else if (arr_size(arr) == 2 && ft_strcmp(arr[1], "-c") == 0)
	{
		unlink(path_file);
	}
	else
	{
		ft_putstr("history: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
