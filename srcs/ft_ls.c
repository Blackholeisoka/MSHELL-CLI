/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:36:10 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/08 20:36:10 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <locale.h>

void	ft_putstr_space(int max, int length)
{
	for (int i = 0; i < (max - length) + 1; i++)
		ft_putstr(" ");
}

int	ft_size_len(char *path)
{
	struct stat	st;
	char		buf[64];

	stat(path, &st);
	if (S_ISDIR(st.st_mode))
		return (1);
	snprintf(buf, sizeof(buf), "%ld", st.st_size);
	return (ft_strlen(buf));
}

int	is_dir_point(char *str)
{
	if ((ft_strcmp(str, ".") == 0) || (ft_strcmp(str, "..") == 0))
			return (1);
	return (0);
}

void	ft_list_file_basic(char *path)
{
	DIR	*dir = opendir(path);
	struct dirent	*e;
	int	i;

	if (!dir)
	{
		ft_putstr("ls: cannot open directory\n");
		return ;
	}
	i = 0;
	while ((e = readdir(dir)))
	{
		if (is_dir_point(e->d_name))
			continue ;
		if (e->d_type == DT_DIR)
			ft_putstr("./");
		ft_putstr(e->d_name);
		ft_putstr(" ");
		if (i > 0 && (i % 5 == 0))
			ft_putstr("\n");
		i++;
	}
	closedir(dir);
	ft_putstr("\n");
}

void	ft_chmod_print(char *file_or_dir)
{
	struct stat	st;

	stat(file_or_dir, &st);

	if (S_ISDIR(st.st_mode))
		ft_putstr("d");
	else if (S_ISLNK(st.st_mode))
		ft_putstr("l");
	else
		ft_putstr("-");

	ft_putstr(((st.st_mode & S_IRUSR) ? "r" : "-"));
	ft_putstr(((st.st_mode & S_IWUSR) ? "w" : "-"));
	ft_putstr(((st.st_mode & S_IXUSR) ? "x" : "-"));

	ft_putstr(((st.st_mode & S_IRGRP) ? "r" : "-"));
	ft_putstr(((st.st_mode & S_IWGRP) ? "w" : "-"));
	ft_putstr(((st.st_mode & S_IXGRP) ? "x" : "-"));

	ft_putstr(((st.st_mode & S_IROTH) ? "r" : "-"));
	ft_putstr(((st.st_mode & S_IWOTH) ? "w" : "-"));
	ft_putstr(((st.st_mode & S_IXOTH) ? "x" : "-"));
}

int ft_print_file_size(char *file_or_dir)
{
	struct stat	st;
	char	str_size[1024];

	stat(file_or_dir, &st);

	if (S_ISDIR(st.st_mode))
	{
		ft_putstr("-");
		return (1);
	}
	else
	{
		ft_putnbr(st.st_size);
		snprintf(str_size, sizeof(str_size), "%ld", st.st_size);
		return (ft_strlen(str_size));
	}
}
void	ft_print_owner_file(char *file_or_dir)
{
	struct passwd	*pw;
	struct stat	st;

	stat(file_or_dir, &st);
	pw = getpwuid(st.st_uid);
	if (pw)
		ft_putstr(pw->pw_name);
	else
		ft_putnbr(st.st_uid);
}

void	ft_print_file_date(char *file_or_dir)
{
	char	date[100];
	struct stat	st;

	stat(file_or_dir, &st);
	setlocale(LC_TIME, "");
	strftime(date, sizeof(date), "%e %b %H:%M", localtime(&st.st_mtime));
	ft_putstr(date);
}

void	ft_list_file_stat(char *path)
{
	DIR	*dir = opendir(path);
	struct dirent	*e;
	struct stat	st;
	char	file_or_dir[1024];
	int	max;

	max = 0;
	if (!dir)
	{
		ft_putstr("ls: cannot open directory\n");
		return ;
	}
	while ((e = readdir(dir)))
	{
		if (is_dir_point(e->d_name))
			continue ;
		snprintf(file_or_dir, sizeof(file_or_dir), "%s/%s", path, e->d_name);
		if (ft_size_len(file_or_dir) > max)
			max = ft_size_len(file_or_dir);
	}
	rewinddir(dir);
	while ((e = readdir(dir)))
	{
		snprintf(file_or_dir, sizeof(file_or_dir), "%s/%s", path, e->d_name);
		if (stat(file_or_dir, &st) == -1)
		{
			ft_putstr("ls: cannot access '");
			ft_putstr(e->d_name);
			ft_putstr("'\n");
			continue ;
		}
		ft_chmod_print(file_or_dir);
		ft_putstr(" ");
		ft_print_file_size(file_or_dir);
		ft_putstr_space(max, ft_size_len(file_or_dir));
		ft_print_owner_file(file_or_dir);
		ft_putstr(" ");
		ft_print_file_date(file_or_dir);
		ft_putstr(" ");
		if (e->d_type == DT_DIR && !is_dir_point(e->d_name))
			ft_putstr("./");
		ft_putstr(e->d_name);
		ft_putstr("\n");
	}
	closedir(dir);
}

int	ft_ls(char **arr)
{
	if (arr_size(arr) == 1)
	{
		ft_list_file_basic(".");
	}
	else if(arr_size(arr) == 2)
	{
		if (arr[1][0] != '-')
		{
			ft_list_file_basic(arr[1]);
		}
		else if ((ft_strcmp(arr[1], "-l") == 0) || (ft_strcmp(arr[1], "-la") == 0))
		{
			ft_list_file_stat(".");
		}
		else
		{
			ft_putstr("ls: bad option: ");
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
	}
	else if (arr_size(arr) == 3)
	{
		if ((ft_strcmp(arr[1], "-l") == 0) || (ft_strcmp(arr[1], "-la") == 0))
		{
			ft_list_file_stat(arr[2]);
		}
		else
		{
			ft_putstr("ls: bad option: ");
			ft_putstr(arr[1]);
			ft_putstr("\n");
		}
	}
	else
	{
		ft_putstr("ls: too many arguments\n");
	}
	return (0);
}
