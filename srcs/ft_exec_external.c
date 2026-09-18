/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 18:14:47 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/18 18:14:47 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
extern	char	**environ;

int	ft_exec_external(char **arr)
{
	pid_t	pid;
	char	*path;

	path = ft_find_path(arr[0]);
	if (!path)
	{
		ft_putstr(RED "command not found: " RESET);
		ft_putstr(arr[0]);
		ft_putstr("\n");
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		execve(path, arr, environ);
		exit(127);
	}
	waitpid(pid, NULL, 0);
	free(path);
	return (0);
}
