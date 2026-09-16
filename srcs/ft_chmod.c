/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:51:49 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 20:51:49 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int	ft_atoi_octal(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '7')
			result = result * 8 + (str[i++] - '0');
		else return (-1);
	}
	return (result);
}

int	ft_chmod(char **arr)
{
	int	mode;

	mode = 0;
	if (arr_size(arr) == 1)
	{
		ft_putstr("chmod: missing operand\n");
	}
	else if (arr_size(arr) == 2)
	{
		ft_putstr("chmod: missing operand after '");
		ft_putstr(arr[1]);
		ft_putstr("'\n");
	}
	else if (arr_size(arr) >= 3 && arr[1][0] != '-')
	{
		mode = ft_atoi_octal(arr[1]);
		if (mode == -1)
		{
			ft_putstr("chmod: invalid mode: '");
			ft_putstr(arr[1]);
			ft_putstr("'\n");
			return (0);
		}	
		for (int i = 2; arr[i] != NULL; i++)		
		{
			if (chmod(arr[i], mode) == -1)
			{
				ft_putstr("chmod: cannot access '");
				ft_putstr(arr[i]);
				ft_putstr("': No such file or directory\n");	
			}
		}
	}
	else
	{
		ft_putstr("chmod: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
