/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 01:37:34 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/04 01:37:34 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_a_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	words_counts(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((!is_a_charset(str[i], charset)) && (i == 0 || is_a_charset(str[i
					- 1], charset)))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset, int *i)
{
	char	*dest;
	int		j;

	j = 0;
	while (str[(*i) + j] != '\0' && !is_a_charset(str[(*i) + j], charset))
		j++;
	dest = malloc(j + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str[(*i)] != '\0' && !is_a_charset(str[(*i)], charset))
	{
		dest[j] = str[(*i)];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc((words_counts(str, charset) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (str[i] != '\0')
	{
		while (is_a_charset(str[i], charset) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			arr[j++] = ft_strdup(str, charset, &i);
	}
	arr[j] = NULL;
	return (arr);
}
