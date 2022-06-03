/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:03:53 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/14 11:39:03 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if ((size_t)(dst - src) >= len)
		return (ft_memcpy(dst, src, len));
	while (len--)
		*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}
