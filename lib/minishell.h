/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:56 by jinwolee          #+#    #+#             */
/*   Updated: 2022/05/26 18:19:23 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "../Libft/libft.h"

typedef struct		s_data{
	int		argc;
	char	**argv;
	char	**envp;
	char	**export;
	char	*str;
	char	**cmds;
}					t_data;

/* cd.c */
void	cd_command(t_data *param);

/* utils.c */
char    **copy_env(char **envp, int add);
void	free_matrix(char **matrix);
int		ft_putstrs_fd(char *before, char *str, char *after, int fd);
char	*get_env(char **envp, char *env);

/* export.c */
void	sort_envp(char **envp, int fd, char c);

/* pwd.c */
void	pwd_command(int fd);

/* command.c */
int		check_command(int fd, t_data *param);

/* utils_len.c */
int		ft_find_c_in_str(char *str, char c);

/* utils_signal.c */
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

/* parser.c */
void    parser(t_data *param);

/* main.c */
void	print_logo(void);

/* free.c */
void	free_env(char **env);

#endif
