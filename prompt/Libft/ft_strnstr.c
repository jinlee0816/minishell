/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:11:56 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/17 15:38:57 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] && i + j < len)
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
			if (!to_find[j])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
