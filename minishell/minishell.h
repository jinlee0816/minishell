/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:07:55 by younjkim          #+#    #+#             */
/*   Updated: 2022/05/22 19:24:14 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <sys/types.h>
# include "libft/libft.h"

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