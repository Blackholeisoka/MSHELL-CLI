/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 20:05:44 by blackholeisok     #+#    #+#             */
/*   Updated: 2026/09/03 20:05:44 by blackholeisok    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H
# define FT_TOOLS_H

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
char	*ft_current_path(void);
char	*ft_get_username(void);
char	*ft_skip_whitespaces(char *str);
void	ft_putstr(char *str);
void	ft_print_file(char *str);

#endif
