/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:50:27 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/14 11:37:18 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (size + len_src);
	else
	{
		i = 0;
		while (src[i] && i < size - len_dest - 1)
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = 0;
	}
	return (len_dest + len_src);
}
