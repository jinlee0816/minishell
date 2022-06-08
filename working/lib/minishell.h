/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:56 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 15:43:33 by jinwolee         ###   ########.fr       */
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

typedef struct s_data{
	int		argc;
	char	**argv;
	char	**envp;
	char	**export;
	char	*str;
	char	**cmds;
}			t_data;

/* args.c */
int		count_args(char *str);
void	set_args(char **argv, char *str, int argc);

/* cd.c */
void	cd_command(t_data *param);

/* command.c */
int		check_command(int fd, t_data *param);

/* parser.c */
void	parse(t_data *param);
void	skip_spaces(char **str);

/* utils_signal.c */
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

/* utils.c */
char	**copy_env(char **envp, int add);
void	free_matrix(char **matrix);
int		ft_putstrs_fd(char *before, char *str, char *after, int fd);
char	*get_env(char **envp, char *env);
int		check_quotes(char **str, int *i, char c);

/* utils2.c */
void	skip_spaces(char **str);

#endif
