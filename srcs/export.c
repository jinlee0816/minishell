/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:20:19 by jinwolee          #+#    #+#             */
/*   Updated: 2022/05/26 18:14:28 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sort_envp(char **envp, int fd, char c)
{
	int		i;
	int		len;
	char	**aux;
	char	*tmp;

	aux = copy_env(envp, 0);
	i = 0;
	while (aux[i] && aux[i + 1])
	{
		len = (ft_find_c_in_str(aux[i], c) > ft_find_c_in_str(aux[i + 1], c))
				? ft_find_c_in_str(aux[i], c) : ft_find_c_in_str(aux[i + 1], c);
		if (ft_memcmp(aux[i], aux[i + 1], len) > 0)
		{
			tmp = aux[i];
			aux[i] = aux[i + 1];
			aux[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	put_envp(aux, fd);
}
