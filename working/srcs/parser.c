/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:03:27 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/03 18:12:41 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static int	check_semicolon(t_data *param)
{
	if (!param->str || !ft_memcmp(param->str, ";", 2))
	{
		if (param->str)
			ft_putstr_fd("-bash; syntax error near unexpected token `;'\n", 2);
		free(param->str);
		param->str = 0;
		return (1);
	}
	return (0);
}

void    parse(t_data *param)
{
	int i;

	if (check_semicolon(param))
		return ;
	param->cmds = ft_split(param->str, ';');
	i = 0;
    /*
    if (is_pipe)
        command_pipe();
    else
        command();
    */
    free(param->str);
	param->str = 0;
    free_matrix(param->cmds);
}
