/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 03:22:08 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/10 03:22:08 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft_tools.h"

void	ft_print_current_path(void)
{
	char	*str_path;

	str_path = ft_current_path();
	ft_putstr("[-] ");
	ft_putstr(ft_get_username());
	ft_putstr(" · ~/");
	ft_putstr((str_path + 7 + ft_strlen(ft_get_username())));
	ft_putstr(">\n ▶ ");
	free(str_path);
}

int	main(int argc, char *argv[])
{
	char	*input;
	size_t	size;
	ssize_t	n;
	
	(void)argc;
	(void)argv;
	input = NULL;
	ft_putstr(CLEAR);
	ft_print_file(HEADER);

	while (TRUE)
	{
		ft_print_current_path();
		n = getline(&input, &size, stdin);
		if (n < 0)
			break ;
		if (n > 0 && input[n - 1] == '\n')
			input[n - 1] = '\0';
		if (input[0] == '\0')
			continue ;
		if (ft_strcmp(ft_skip_whitespaces(input), "exit") == 0)
			break ;
		ft_parse_cmd(input);
	}
	ft_putstr("\n[-] mshell: session ended\n");
	return (0);
}
