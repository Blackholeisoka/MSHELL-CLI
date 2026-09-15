/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:23:01 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/16 01:23:01 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>


static t_help	arr_help[] = {
	{"pwd", "print the current working directory"},
	{"cd", "change the current directory"},
	{"clear", "clear the screen and redraw the header"},
	{"echo", "display a line of text"},
	{"whoami", "print the current user name"},
	{"env", "print all environment variables"},
	{"printenv", "print the value of a variable"},
	{"export", "set an environment variable"},
	{"cat", "print file contents (supports * glob)"},
	{"ls", "list directory contents"},
	{"touch", "create empty files"},
	{"mkdir", "create directories"},
	{"rm", "remove files"},
	{"rmdir", "remove empty directories"},
	{"cp", "copy files"},
	{"mv", "move or rename files"},
	{"ln", "create hard or symbolic links"},
	{"wc", "count lines, words and characters"},
	{"head", "print the first lines of a file"},
	{"tail", "print the last lines of a file"},
	{"grep", "search a pattern in files"},
	{"diff", "compare two files line by line"},
	{"uniq", "filter repeated lines"},
	{"tac", "print a file in reverse"},
	{"rev", "reverse each line of a file"},
	{"which", "locate a command in PATH"},
	{"date", "print the current date and time"},
	{"basename", "strip directory from a path"},
	{"dirname", "strip filename from a path"},
	{"yes", "output a string repeatedly"},
	{"kill", "send a signal to a process"},
	{"history", "show command history"},
	{"help", "show this help"},
	{NULL, NULL}
};

static t_help	arr_help_option[] = {
	{"pwd", "<none>   print working directory"},
	{"cd", "<none>   go to HOME\n  <dir>    change to directory"},
	{"clear", "<none>   clear and redraw header"},
	{"echo", "<none>   print arguments\n  -n       no trailing newline"},
	{"whoami", "<none>   print user name"},
	{"env", "<none>   print all variables"},
	{"printenv", "<var>    print one variable"},
	{"export", "<VAR=val>   set a variable"},
	{"cat", "<file>   print file(s)\n  *        glob current dir\n  *.ext    glob by extension"},
	{"ls", "<none>   list current dir\n  <dir>    list a directory\n  -l       long format\n  -la      long format (same as -l)"},
	{"touch", "<file>   create empty file(s)"},
	{"mkdir", "<dir>    create directory(ies)"},
	{"rm", "<file>   remove file(s)"},
	{"rmdir", "<dir>    remove empty dir(s)"},
	{"cp", "<src> <dst>       copy to file\n  <src...> <dir>    copy into dir"},
	{"mv", "<src> <dst>       rename/move\n  <src...> <dir>    move into dir"},
	{"ln", "<src> <dst>    hard link\n  -s <src> <dst>   symbolic link"},
	{"wc", "<file>   lines words chars\n  -l       lines only\n  -c       chars only"},
	{"head", "<file>   first 10 lines\n  -n <N>   first N lines"},
	{"tail", "<file>   last 10 lines\n  -n <N>   last N lines"},
	{"grep", "<pat> <file>   search pattern\n  -n       show line numbers\n  -v       invert match"},
	{"diff", "<f1> <f2>   compare two files"},
	{"uniq", "<file>   remove adjacent dups\n  -d       only duplicates\n  -u       only uniques"},
	{"tac", "<file>   print in reverse"},
	{"rev", "<file>   reverse each line"},
	{"which", "<cmd...>   locate in PATH"},
	{"date", "<none>   current date/time"},
	{"basename", "<path>   strip directory"},
	{"dirname", "<path>   strip filename"},
	{"yes", "<none>   repeat 'y'\n  <str>    repeat string"},
	{"kill", "<pid...>   send SIGTERM"},
	{"history", "<none>   show history\n  -c       clear history"},
	{"help", "<none>   list commands\n  <cmd>    detail a command"},
	{NULL, NULL}
};

int	ft_help_size(t_help *tab)
{
	int	i;

	i = 0;
	while (tab[i].command != NULL)
		i++;
	return (i);
}

int	ft_help(char **arr)
{
	int	j;

	j = 0;
	if (arr_size(arr) == 1)
	{
		for (int i = 0; arr_help[i].command != NULL; i++)
		{
			ft_putstr(arr_help[i].command);
			ft_putstr(": ");
			ft_putstr(arr_help[i].description);
			ft_putstr("\n");
			ft_putstr("\n");
		}
		ft_putstr("type 'help <command>' for details\n");
		ft_putstr("\n");
	}
	else if (arr_size(arr) >= 2 && arr[1][0] != '-')
	{
		for (int i = 1; arr[i] != NULL; i++)
		{
			j = 0;
			while (arr_help_option[j].command != NULL)
			{
				if(ft_strcmp(arr_help_option[j].command, arr[i]) == 0) break ; 
				j++;
			}
			if (j == ft_help_size(arr_help_option))
			{
				ft_putstr("help: ");
				ft_putstr(arr[i]);
				ft_putstr(" does not exist\n");
			}
			else
			{
				ft_putstr(arr_help[j].command);
				ft_putstr(" - ");
				ft_putstr(arr_help[j].description);
				ft_putstr("\n");
				ft_putstr(arr_help_option[j].command);
				ft_putstr(": ");
				ft_putstr(arr_help_option[j].description);
				ft_putstr("\n");
				ft_putstr("\n");
			}
		}
	}
	else
	{
		ft_putstr("help: bad option: ");
		ft_putstr(arr[1]);
		ft_putstr("\n");
	}
	return (0);
}
