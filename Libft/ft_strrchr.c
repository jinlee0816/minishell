/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:56:07 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/17 13:31:48 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;

	if (c > 255)
		return ((char *)&str[0]);
	len = ft_strlen(str);
	while (len > -1)
	{
		if (str[len] == c)
			break ;
		len--;
	}
	if (len < 0)
		return (NULL);
	return ((char *)&str[len]);
}
