/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:53:23 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/07 16:57:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getprompt(void)
{
	char	prompt[1000];
	char	cwd[1000];

	getcwd(cwd, 1000);
	ft_strlcpy(prompt, "\e[1;31m", 1000);
	ft_strlcat(prompt, getenv("USER"), 1000);
	ft_strlcat(prompt, ":", 1000);
	ft_strlcat(prompt, "\e[1;35m", 1000);
	if (!ft_strncmp(cwd, getenv("HOME"), ft_strlen(getenv("HOME"))))
	{
		ft_strlcat(prompt, "~", 1000);
		ft_strlcat(prompt, cwd + ft_strlen(getenv("HOME")), 1000);
	}
	else
		ft_strlcat(prompt, cwd, 1000);
	ft_strlcat(prompt, "\e[0m", 1000);
	ft_strlcat(prompt, "$ ", 1000);
	return (ft_strdup(prompt));
}
