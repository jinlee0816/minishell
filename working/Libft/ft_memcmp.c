/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:50:35 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/10 16:07:53 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*point1;
	const unsigned char	*point2;
	size_t				i;

	i = 0;
	point1 = (unsigned char *)ptr1;
	point2 = (unsigned char *)ptr2;
	while (i < num)
	{
		if (*point1 != *point2)
			return (*point1 - *point2);
		++point1;
		++point2;
		++i;
	}
	return (0);
}
