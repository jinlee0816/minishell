/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:32:16 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 15:32:49 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

int	count_args(char *str)
{
	int	n;

	n = 0;
	skip_spaces(&str);
	while (*str)
	{
		skip_spaces(&str);
		n++;
		str += ft_strlen_arg(str);
		skip_spaces(&str);
	}
	return (n);
}

void	set_args(char **argv, char *str, int argc)
{
	int		i;
	int		len;

	i = 0;
	skip_spaces(&str);
	while (i < argc)
	{
		skip_spaces(&str);
		len = ft_strlen_arg(str);
		argv[i] = ft_strldup(str, len);
		rm_token(&(argv[i]));
		i++;
		str += len;
		skip_spaces(&str);
	}
}
