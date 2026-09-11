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

#define HEADER "header.txt"
#define CLEAR "\033[H\033[2J\033[3J"
#define TRUE 1
#define FALSE 0

typedef struct s_parsing
{
	char	*command;
	int	(*function)(char **input_params);
}	t_parsing;

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
int	arr_size(char **arr);
int	ft_parse_cmd(char *str);
int	ft_atoi(char *str);
int	ft_file_count_line(char *file);
int	ft_write_history(char *input);
char	*ft_current_path(void);
char	*ft_get_username(void);
char	*ft_skip_whitespaces(char *str);
char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);
void	ft_print_file(char *str);
void	ft_putnbr(int nb);
int	ft_pwd(char **arr);
int	ft_head(char **arr);
int	ft_tail(char **arr);
int	ft_history(char **arr);
int	ft_clear(char **arr);
int	ft_env(char **arr);
int	ft_touch(char **arr);
int	ft_diff(char **arr);
int	ft_echo(char **arr);
int	ft_mkdir(char **arr);
int	ft_printenv(char **arr);
int	ft_wc(char **arr);
int	ft_export(char **arr);
int	ft_rm(char **arr);
int	ft_rmdir(char **arr);
int	ft_ls(char **arr);
int	ft_whoami(char **arr);
int	ft_cd(char **arr);
int	ft_cat(char **arr);
t_parsing	*ft_get_struct_parsing(void);

#endif
