/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:50:14 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 21:24:43 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static int	ft_strlen_env(char *str)
{
	int	len;

	len = 0;
	while (*str && (ft_isalnum(*str) || *str == '{' || *str == '?'))
	{
		len++;
		str++;
	}
	return (len);
}

static int	change_env(int i, int braces, char *str, t_data *param)
{
	int		len;
	char	*bef;
	char	*aft;
	char	*env;
	char	*aux;

	if (str[i + 1] == '{')
		braces = 1;
	len = ft_strlen_env(str + i + 1) + 1 + braces;
	bef = ft_strldup(str, i);
	aux = ft_strldup(str + i + 1 + braces, len - 1 - braces * 2);
	env = NULL;
	if (!ft_memcmp(aux, "?", 2))
		env = ft_itoa(param->before_state);
	aft = ft_strdup(str + i + len);
	if (!env)
		env = ft_strdup(get_env(param->envp, aux));
	free(aux);
	len = ft_strlen(env);
	aux = ft_strjoin(bef, env);
	free(str);
	str = ft_strjoin(aux, aft);
	free_strings(bef, aux, aft, env);
	return (len);
}

static void	free_strings(char *str1, char *str2, char *str3, char *str4)
{
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

int	check_env(char *str, t_data *param)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& (str[i + 1] && !ft_isspace(str[i + 1]) && str[i + 1] != '\''
				&& str[i + 1] != '"' && str[i + 1] != '/'))
			i += change_env(i, 0, str, param) - 1;
		i++;
	}
	return (0);
}
