/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:55:12 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/13 18:39:04 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_long(int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_putchar(char *str, int n, int len)
{
	if (n < 0)
	{
		str[len] = -1 * (n % 10) + 48;
		n = -1 * n / 10;
	}
	else
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	if (n != 0)
		str = ft_putchar(str, n, len - 1);
	return (str);
}

char	*ft_itoa(int n)
{
	int		negative;
	int		len;
	char	*str;

	negative = 1;
	if (n < 0)
	{
		negative = -1;
		len = how_long(n / 10) + 2;
	}
	else
		len = how_long(n / 10) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str = ft_putchar(str, n, len - 2);
	if (n < 0)
		str[0] = '-';
	str[len - 1] = 0;
	return (str);
}
