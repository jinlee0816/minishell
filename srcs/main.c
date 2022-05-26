/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:21:17 by jinwolee          #+#    #+#             */
/*   Updated: 2022/05/26 17:54:36 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static void	put_prompt(char **envp)
{
	char *home;
	char *path;
	char cwd[4097];

	ft_putstr_fd("\033[1;35m",1);
	home = get_env(envp, "HOME");
	getcwd(cwd, 4096);
	if (ft_memcmp(cwd, home, ft_strlen(home)))
		path = ft_strdup(cwd);
	else
		path = ft_strjoin("~", cwd + ft_strlen(home));
	write(2, "minishell : ", 12);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\033[0m",1);
	free(path);
}

static void	init_param(t_data **param, char **envp, int *ret_len)
{
	(*param) = (t_data *)malloc(sizeof(t_data));
	(*param)->envp = copy_env(envp, 0);
	(*param)->export = (char **)ft_calloc(sizeof(char *), 1);
	(*param)->str = 0;
	ret_len[0] = 1;
}

static void	print_logo(void)
{
	printf("\033[1;35m\
	 __  __ _       _     _          _ _ \n\
	|  \\/  (_)_ __ (_)___| |__   ___| | |\n\
	| |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n\
	| |  | | | | | | \\__ \\ | | |  __/ | |\n\
	|_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|\n\033[0m \
	\t\t\tby younjkim & jinwolee\n\n");
}

static char	*signal_readline(char *line, char **envp)
{
	(void)envp;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	put_prompt(envp);
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
	t_data	*param;
	int		ret_len[2];

	(void)argv;
	line = NULL;
	if (argc != 1)
		return (ft_putstr_fd("Error : Wrong number of arguments!\n", 2), 1);
	print_logo();
	init_param(&param, envp, ret_len);
	while (1)
	{
		param->str = signal_readline(param->str, envp);
		parse(param);
	}
	return (0);
}