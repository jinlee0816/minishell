/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:08:01 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 15:54:19 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static void	env_command(t_data *param, int fd)
{
	int	i;

	i = 0;
	if (param->argc != 1)
	{
		ft_putstrs_fd("env: ‘", param->argv[1],
			"’: Permission denied\n", 2);
		return ;
	}
	while (param->envp[i])
		ft_putstrs_fd(param->envp[i++], "\n", 0, fd);
}

static void	echo_command(t_data *param, int fd)
{
	int	i;
	int	nl;

	i = 0;
	if (param->argc > 1 && !ft_memcmp(param->argv[1], "-n", 3))
		i = 1;
	nl = i;
	while (++i < param->argc)
		ft_putstr_fd(param->argv[i], fd);
	if (nl == 1)
		write(fd, "\n", 1);
}

static void	zsh_error(void)
{
	ft_putstr_fd("zsh: Permission denied\n", 2);
	return ;
}

static int	check_command_sub(int fd, t_data *param)
{
	char	*path;
	char	cwd[4097];

	path = 0;
	if (!ft_memcmp(param->argv[0], "echo", 5))
		echo_command(param, fd);
	else if (!ft_memcmp(param->argv[0], "pwd", 4))
		ft_putstrs_fd(getcwd(cwd, 4096), "\n", 0, fd);
	else if (!ft_memcmp(param->argv[0], "cd", 3))
	{
		path = ft_strdup(param->argv[1]);
		cd_command(param);
		if (path && !ft_strncmp(path, "-", 2))
			ft_putstrs_fd(getcwd(cwd, 4096), "\n", 0, fd);
		free(path);
	}
	else
		return (1);
	return (0);
}

int	check_command(int fd, t_data *param)
{
	if (!check_command_sub(fd, param))
		return (1);
	else if (!ft_memcmp(param->argv[0], "env", 4))
		env_command(param, fd);
	else if (!ft_memcmp(param->argv[0], "./", 2)
		|| !ft_memcmp(param->argv[0], "../", 3)
		|| !ft_memcmp(param->argv[0], "/", 1))
		zsh_error();
	else if (!ft_memcmp(param->argv[0], "export", 7)
		|| !ft_memcmp(param->argv[0], "unset", 6))
		param->envp = multiple_env(param, fd);
	else if (!ft_memcmp(param->argv[0], "exit", 5)
		|| !ft_memcmp(param->argv[0], "q", 2))
		exit_command(param);
	else
		return (0);
	return (1);
}
