/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:07:55 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/07 17:54:37 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

// 종료 코드 define
# define REDIRIN 1
# define CMD_NOT_FOUND 127
# define EXIT_SIGINT 130
# define EXIT_EXIT 254

typedef struct s_m_vars
{
	int		fork;
	int		dup_fd[2];
	int		status;
	int		exit_status;
}	t_m_vars;

// main.c
void	print_logo(void);
char	**ft_env_init(char **envp);
char	*signal_readline(char *line, char **envp);

// signal_util.c
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

// free.c
void	free_env(char **env);

#endif