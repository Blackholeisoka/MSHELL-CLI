/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:05:25 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/13 16:05:25 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <locale.h>
#include <time.h>
#include <unistd.h>

int	ft_date(char **arr)
{
	char	str[1024];
	time_t	now;

	now = time(NULL);
	setlocale(LC_TIME, "");
	if (arr_size(arr) == 1)
	{
		strftime(str, sizeof(str), "%a %e %b %Y %H:%M:%S %Z", localtime(&now));
		ft_putstr(str);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr(RED "date: bad option: " RESET);
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
