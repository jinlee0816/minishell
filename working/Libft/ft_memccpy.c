/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:30:49 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/13 14:22:29 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t num)
{
	unsigned char	*new_dest;
	unsigned char	*new_source;
	size_t			i;

	if (!dest && !source)
		return (NULL);
	new_dest = dest;
	new_source = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		new_dest[i] = new_source[i];
		if (new_source[i] == (unsigned char)c)
			return (new_dest + i + 1);
		i++;
	}
	return (NULL);
}
