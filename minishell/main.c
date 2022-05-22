/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:28:10 by younjkim          #+#    #+#             */
/*   Updated: 2022/05/22 19:42:54 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_logo(void)
{
	printf("\033[1;35m\
	 __  __ _       _     _          _ _ \n\
	|  \\/  (_)_ __ (_)___| |__   ___| | |\n\
	| |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n\
	| |  | | | | | | \\__ \\ | | |  __/ | |\n\
	|_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|\n\033[0m \
	\t\t\tby younjkim & jinwolee\n\n");
}

char	**ft_env_init(char **envp)
{
	int		i;
	int		size;
	char	**tmp;

	i = 0;
	size = 0;
	while (envp[++i])
		size++;
	tmp = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		tmp[i] = ft_strdup(envp[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*signal_readline(char *line, char **envp)
{
	(void)envp;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	line = readline("\033[1;35m~Minishell$\033[0m ");
	if (!line)
	{
		ft_putstr_fd("exit\n", 2);
		exit(0);
	}
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**env;

	(void)argv;
	line = NULL;
	env = ft_env_init(envp);
	if (argc != 1)
		return (ft_putstr_fd("Error : Wrong number of arguments!\n", 2), 1);
	print_logo();
	while (1)
	{
		line = signal_readline(line, envp);
		free(line);
	}
	free_env(env);
	return (0);
}
