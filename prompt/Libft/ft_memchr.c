/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:33:37 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/13 15:36:17 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (*str == (unsigned char)value)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
