/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:59:45 by jinwolee          #+#    #+#             */
/*   Updated: 2022/06/03 17:58:34 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenth(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*output;

	i = 0;
	len = ft_strlenth(src);
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL);
	while (src[i++])
		output[i] = src[i];
	output[i] = 0;
	return (output);
}
