/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:10:34 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/03 22:10:34 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "../includes/ft_tools.h"

t_parsing	*ft_get_struct_parsing(void)
{
	 static t_parsing	parsing[] = {
		{"pwd", ft_pwd},
		{"clear", ft_clear},
		{"cd", ft_cd},
		//{"ls", ft_ls},
		//{"mv", ft_mv},
		//{"cp", ft_cp},
		//{"cat", ft_cat},
		{NULL, NULL}
	};
	return (parsing);
}

int	ft_parse_cmd(char *str)
{
	char	**string_params;
	t_parsing *arr;
	int	i;

	i = 0;
	arr = ft_get_struct_parsing();
	string_params = ft_split(str, " ");
	while (arr[i].command)
	{
		if (ft_strcmp(string_params[0], arr[i].command) == 0)
			return (arr[i].function(string_params));
		i++;
	}
	return (0);
}
