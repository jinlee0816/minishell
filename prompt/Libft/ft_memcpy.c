/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:26:42 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/03 19:27:10 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char		*new_dest;
	const unsigned char	*new_source;
	size_t				i;

	if (!dest && !source)
		return (dest);
	new_dest = (unsigned char *)dest;
	new_source = (unsigned char *)source;
	i = -1;
	while (++i < num)
		new_dest[i] = new_source[i];
	return (new_dest);
}
