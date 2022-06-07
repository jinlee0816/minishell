/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:28:10 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/07 17:52:09 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_m_vars	*g_vars;

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

void	sig_handle(int signo, siginfo_t *info, void *other)
{
	(void)info;
	(void)other;
	if (signo == SIGINT)
	{
		g_vars->exit_status = EXIT_SIGINT;
		if (g_vars->fork != 0)
			exit(EXIT_SIGINT);
		printf("\n");
		if (g_vars->status == 0)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		return ;
	}
}

void	init_shell(struct termios term, int argc, char **argv)
{
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	tcgetattr(STDIN_FILENO, &term);
	sa.sa_signaction = sig_handle;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &term);
	g_vars->fork = 0;
	g_vars->dup_fd[0] = dup(STDIN_FILENO);
	g_vvars->dup_fd[1] = dup(STDOUT_FILENO);
	print_logo();
}

void	exit_shell(void)
{
	int	fork;

	fork = g_vars->fork;
	rl_clear_history();
	close(g_vars->dup_fd[0]);
	close(g_vars->dup_fd[1]);
	if (!fork)
		ft_putendl_fd("exit", STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	term;
	char			*line;
	char			*prompt;

	ft_env_init(envp);
	if (argc != 1)
		return (ft_putstr_fd("Error : Wrong number of arguments!\n", 2), 1);
	init_shell(term, argc, argv);
	while (1)
	{
		prompt = getprompt();
		g_vars->status = 0;
		line = readline(prompt);
		free(prompt);
		if (!line)
			exit_shell();
		if (line[0] != '\0')
		{
			add_history(line);
			g_vars->status = 1;
			g_vars->exit_status = shell_line(line);
			if (g_vars->exit_status == EXIT_EXIT)
				exit_shell();
		}
	}
}
