/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:59:51 by younjkim          #+#    #+#             */
/*   Updated: 2022/05/26 18:18:18 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	free_env(char **env)
{
	int		i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			free(env[i]);
			env[i] = NULL;
		}
		i++;
	}
	free(env);
	env = NULL;
}
