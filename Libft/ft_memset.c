/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:03:53 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/09 17:00:48 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*new;
	size_t			i;

	if (!ptr && value < 0)
		return (NULL);
	new = ptr;
	i = -1;
	while (++i < num)
		new[i] = value;
	return (new);
}
