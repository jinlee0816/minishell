#ifndef MINISHELL_H
# define MINISHELL_H
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# define MAX_INPUT_SIZE 1024
# define MAX_TOKEN 512

/* minishell.c */
void    do_pipe(char **tokens, int pipe_idx[MAX_TOKEN], int pipe_cnt);
void    run_commands(char **tokens);

/* utils.c */
char	**ft_split(char *str, char *charset);
void	print_minishell(void);
void    cmd_cd(int argc, char **tokens);

#endif
