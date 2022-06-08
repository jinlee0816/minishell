/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:03:27 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 15:54:00 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	skip_spaces(char **str)
{
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
}

static int	check_env(char **str, t_data *param)
{
	int	i;

	i = 0;
	while ((*str) && (*str)[i])
	{
		if (((*str)[i] == '\'' && check_quotes(str, &i, '\''))
			|| (*str)[i] == '\"' && check_quotes(str, &i, '\"'))
			return (1);
		if ((*str)[i] == '$' && !(!(*str)[i + 1]
			|| ft_isspace((*str)[i + 1]) || (*str)[i + 1] == '\''
			|| (*str)[i + 1] == '"' || (*str)[i + 1] == '/'))
			i += change_env(i, str, param) - 1;
			// 환경변수 구현 : 아직 안됨
		i++;
	}
	return (0);
}

void	parse(t_data *param)
{
	int	i;
	int	flag;

	param->cmds = ft_split(param->str, ';');
	i = 0;
	while (param->cmds[i])
	{
		flag = check_env(&(param->cmds[i]), param);
		if (flag == 0)
			break ;
		param->argc = count_args(param->cmds[i]);
		param->argv = (char **)malloc(sizeof(char *) * (param->argc + 1));
		//argv에 넣고 command or pipe 처리 : command 실제 이행도 여기서 이루어짐
	}
	free(param->str);
	param->str = 0;
	free_matrix(param->cmds);
}
