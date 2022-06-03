/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:46:28 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/13 18:43:58 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	show(int a, int fd)
{
	int		q;
	int		r;
	char	c;

	q = a / 10;
	r = a % 10;
	c = '0' + r;
	if (q == 0)
	{
		write(fd, &c, 1);
		return ;
	}
	show(q, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		show(-1 * n, fd);
	}
	else
		show(n, fd);
}
