/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whoami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:09:55 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 00:09:55 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_whoami(char **arr)
{
	if (arr_size(arr) == 1)	
	{
		ft_putstr(ft_get_username());
	}
	else
	{
		ft_putstr("whoami: bad option: ");
		ft_putstr(arr[1]);
	}
	ft_putstr("\n");
	return (0);
}
