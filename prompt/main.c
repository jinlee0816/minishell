
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
# include <readline/readline.h>

# include "Libft/libft.h"

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
static char	*signal_readline(char *line, char **envp);
/* main.c */
static void	print_logo(void);

/* free.c */
void	free_env(char **env);







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

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	//rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}

void	sigquit_handler(int sig)
{
	(void)sig;
}

char    **copy_env(char **envp, int add)
{
	int		len;
	int		i;
	char	**cpy;

	len = 0;
	while (envp[len])
		len++;
    cpy = (char **)ft_calloc(sizeof(char *), (len + add + 1));
	if (!cpy)
		return (0);
	i = 0;
	// while (i++ < len)
	// 	cpy[i] = ft_strdup(envp[i]);
	return (cpy);
}

char	*get_env(char **envp, char *env)
{
	int		i;
	int		len;
	char	*tmp;

	env = ft_strjoin(env, "=");
	len = strlen(env);
	i = 0;
	while (envp[i] && ft_memcmp(env, envp[i], len))
		i++;
	if (envp[i])
		tmp = envp[i] + len;
	else
		tmp = 0;
	free(env);
	return (tmp);
}

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

static char	*signal_readline(char *line, char **envp)
{
	(void)envp;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	put_prompt(envp);
	line = readline("\033[1;35m/$\033[0m ");
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
	if (argc != 1)
		return (ft_putstr_fd("Error : Wrong number of arguments!\n", 2), 1);
	print_logo();
	init_param(&param, envp, ret_len);
    param->str = NULL;
	while (1)
	{
		param->str = signal_readline(param->str, envp);
		// parse(param);
	}
	return (0);
}