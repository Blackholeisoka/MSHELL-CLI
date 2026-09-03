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
#include <stdlib.h>
#include <fcntl.h>

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
