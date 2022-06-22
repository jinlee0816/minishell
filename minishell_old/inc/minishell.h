/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:07:55 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/07 18:47:29 by younjkim         ###   ########.fr       */
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
# include "../libft/libft.h"

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
void	sig_handle(int signo, siginfo_t *info, void *other);
void	init_shell(struct termios term, int argc, char **argv);
void	exit_shell(void);

// input.c
char	*getprompt(void);

// line.c

// vars.c
t_m_vars	*ft_env_init(char **envp);

// free.c
void	free_env(char **env);

#endif