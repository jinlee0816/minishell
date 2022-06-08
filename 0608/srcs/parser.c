/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:03:27 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 20:50:07 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	skip_spaces(char **str)
{
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
}

void	parse(t_data *param)
{
	int	i;
	int	flag;

	param->cmds = ft_split(param->str, ';');
	i = 0;
	while (param->cmds[i])
	{
		if (check_env(param->cmds[i], param))
			break ;
		param->argc = count_args(param->cmds[i]);
		param->argv = (char **)malloc(sizeof(char *) * (param->argc + 1));
		set_args(param->argv, param->cmds[i], param->argc);
		command_or_pipe(param, i);
		i++;
		free_matrix(param->argv);
	}
	free(param->str);
	param->str = 0;
	free_matrix(param->cmds);
}
