/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:43:58 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/14 18:13:48 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*output;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = 0;
	return (output);
}
