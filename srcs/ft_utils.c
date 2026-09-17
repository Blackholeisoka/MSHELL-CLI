/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:19:03 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/03 19:19:03 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_tools.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_file_count_line(char *file)
{
	FILE	*f1;
	char	*r1;
	char	f1_line[1024];
	int		count;

	f1 = fopen(file, "r");
	if (!f1)
		return (-1);
	count = 0;
	while (TRUE)
	{
		f1_line[0] = '\0';
		r1 = fgets(f1_line, sizeof(f1_line), f1);
		if (!r1)
			break ;
		count++;
	}
	fclose(f1);
	return (count);
}

char	*ft_get_username(void)
{
	char	*str;

	if (getenv("USER"))
		str = getenv("USER");
	else if (getenv("LOGNAME"))
		str = getenv("LOGNAME");
	else
		str = "unknown";
	return (str);
}

char	*ft_current_path(void)
{
	return (getcwd(NULL, 0));
}

int	ft_match(char *str, char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (str[i] != token[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_logo_char(char c)
{
	ft_putstr(WHITE);
	ft_putstr(BOLD);
	write(1, &c, 1);
	ft_putstr(YELLOW);
	ft_putstr(BOLD);
}

void	ft_print_file(char *str)
{
	int		fd;
	int		n;
	int		i;
	int		line;
	char	buff[1024];

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("mshell: file not found.\n");
		return ;
	}
	line = 1;
	while ((n = read(fd, buff, sizeof(buff) - 1)) > 0)
	{
		buff[n] = '\0';
		i = 0;
		while (i < n)
		{
			if (line <= 9
				&& (buff[i] == '|' || buff[i] == '/'
					|| buff[i] == '\\' || buff[i] == '_'))
			{
				ft_print_logo_char(buff[i]);
				i++;
			}
			else if (ft_match(&buff[i], "{MAGENTA}"))
			{
				ft_putstr(MAGENTA);
				i += 9;
			}
			else if (ft_match(&buff[i], "{GREEN}"))
			{
				ft_putstr(GREEN);
				i += 7;
			}
			else if (ft_match(&buff[i], "{BLUE}"))
			{
				ft_putstr(BLUE);
				i += 6;
			}
			else if (ft_match(&buff[i], "{YELLOW}"))
			{
				ft_putstr(YELLOW);
				i += 8;
			}
			else if (ft_match(&buff[i], "{BOLD}"))
			{
				ft_putstr(BOLD);
				i += 6;
			}
			else if (ft_match(&buff[i], "{RESET}"))
			{
				ft_putstr(RESET);
				i += 7;
			}
			else
			{
				write(1, &buff[i], 1);
				if (buff[i] == '\n')
					line++;
				i++;
			}
		}
	}
	close(fd);
}

int	ft_write_history(char *input)
{
	FILE	*f1;
	int		file_count;
	char	path_file[1024];

	snprintf(path_file, sizeof(path_file), "%s/.history", getenv("HOME"));
	file_count = ft_file_count_line(path_file);
	if (file_count == -1)
		file_count = 0;
	f1 = fopen(path_file, "a");
	if (!f1)
		return (1);
	fprintf(f1, "%d: %s\n", file_count + 1, input);
	fclose(f1);
	return (0);
}

char	*ft_skip_whitespaces(char *str)
{
	while (*str == 32)
		str++;
	return (str);
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
