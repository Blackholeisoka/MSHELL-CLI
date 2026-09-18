/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:59:46 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/18 17:59:46 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strdup_str(char *src)
{
	char	*dest;
	int	i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_find_path(char *input)
{
	char	**path;
	char	result[1024];

	path = ft_split(getenv("PATH"), ":");
	for (int i = 0; path[i] != NULL; i++)
	{
		snprintf(result, sizeof(result), "%s/%s", path[i], input);
		if (access(result, X_OK) == 0)
			return (ft_strdup_str(result));
	}
	return (NULL);
}
