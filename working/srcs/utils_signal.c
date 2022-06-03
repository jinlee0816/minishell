/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:22:55 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/03 18:02:45 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	//rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}

void	sigquit_handler(int sig)
{
	(void)sig;
}