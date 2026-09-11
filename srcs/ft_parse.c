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
#include "../includes/ft_tools.h"

t_parsing	*ft_get_struct_parsing(void)
{
	 static t_parsing	parsing[] = {
		{"pwd", ft_pwd},
		{"ls", ft_ls},
		{"clear", ft_clear},
		{"cd", ft_cd},
		{"cat", ft_cat},
		{"wc", ft_wc},
		{"echo", ft_echo},
		{"whoami", ft_whoami},
		{"touch", ft_touch},
		{"mkdir", ft_mkdir},
		{"rmdir", ft_rmdir},
		{"rm", ft_rm},
		{"env", ft_env},
		{"printenv", ft_printenv},
		{"export", ft_export},
		{"diff", ft_diff},
		{"head", ft_head},
		{"tail", ft_tail},
		{"history", ft_history},
		//{"mv", ft_mv},
		//{"cp", ft_cp},
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
	ft_putstr("command not found: ");
	ft_putstr(string_params[0]);
	ft_putstr("\n");
	return (127);
}
