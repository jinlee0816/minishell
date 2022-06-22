/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:59:22 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/07 17:50:35 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_m_vars		*g_vars;

t_m_vars	*ft_env_init(char **envp)
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
