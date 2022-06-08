/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_or_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:35:50 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 20:44:52 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	command_or_pipe(t_data *param, int j)
{
	int	i;

	i = 0;
	while (param->argv[i] && ft_memcmp(param->argv[i], "|", 2))
		i++;
	if (!param->argv[i])
		param->envp = check_command(param->cmds[j], param);
	else if (param->cmds[j])
	{
		//파이프 처리
	}
	// param->before_state에 상태 종료 넣어야 합니다.
}
