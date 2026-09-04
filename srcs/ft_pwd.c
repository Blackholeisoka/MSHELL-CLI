/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:07:40 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/04 23:07:40 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_pwd(char **arr)
{
	char	*str_path;

	if (arr_size(arr) == 1)	
	{
		str_path = ft_current_path();
		ft_putstr("path: ");
		ft_putstr(str_path);
		free(str_path);
	}
	else
	{
		ft_putstr("pwd: bad option: ");
		ft_putstr(arr[1]);
	}
	ft_putstr("\n");
	return (0);
}
