/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:30 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/08 19:05:42 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

static void	check_one(char c, int *has_two)
{
	if (c == '[')
		(has_two[0])++;
	else if (c == ']')
		(has_two[0])--;
	else if (c == '{')
		(has_two[1])++;
	else if (c == '}')
		(has_two[1])--;
	else if (c == '(')
		(has_two[2])++;
	else if (c == ')')
		(has_two[2])--;
}

static void	check_two(char c, int *has_one)
{
	if (c == '\'' && has_one[0] == 0)
		has_one[0]++;
	else if (c == '\'' && has_one[0] == 1)
		has_one[0]--;
	else if (c == '\"' && has_one[1] == 0)
		has_one[1]++;
	else if (c == '\"' && has_one[1] == 1)
		has_one[1]--;
}

static void	init_variables(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	check_quotes(char *str)
{
	int	i;
	int	has_two[3];
	int	has_one[2];

	init_variables(&has_two[0], &has_two[1], &has_two[2]);
	init_variables(&i, &has_one[0], &has_one[1]);
	while (str[i])
	{
		check_one(str[i], has_two);
		check_two(str[i], has_one);
		if (has_two[0] < 0 || has_two[1] < 0 || has_two[2] < 0)
			return (0);
		i++;
	}
	if (has_two[0] == 0 && has_two[1] == 0 && has_two[2] == 0)
	{
		if (has_one[0] == 0 && has_one[1] == 0)
			return (1);
	}
	ft_putstr_fd("Non finished quotes\n", 2);
	return (0);
}
