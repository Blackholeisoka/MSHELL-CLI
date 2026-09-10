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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define TRUE 1

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
		if (str[i] == '-') sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

int	ft_file_count_line(char *file)
{
	FILE *f1;
	char	*r1;
	char	f1_line[1024];
	int	count;

	f1 = fopen(file, "r"); if (!f1)
		return (-1);
	count = 0;
	while (TRUE)
	{
		f1_line[0] = '\0';
		r1 = fgets(f1_line, sizeof(f1_line), f1);
		if (!r1) break ;
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
		str=  getenv("LOGNAME");
	else
		str = "unknown";
	return (str);
}

char	*ft_current_path(void)
{
	return (getcwd(NULL, 0));
}

void	ft_print_file(char *str)
{
	int	fd;
	int	n;
	char	buff[1024];

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("mshell: header not found.\n");
		return ;
	}
	while ((n = read(fd, buff, sizeof(buff))) > 0)
		write(1, buff, n);
	close(fd);
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
