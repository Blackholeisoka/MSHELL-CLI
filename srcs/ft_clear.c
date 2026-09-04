/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 00:18:49 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/05 00:18:49 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>

int	ft_clear(char **arr)
{
	if (arr_size(arr) == 1)	
	{
		ft_putstr(CLEAR);
		ft_print_file(HEADER);
	}
	else
	{
		ft_putstr("clear: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
