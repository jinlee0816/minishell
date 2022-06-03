/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:58:06 by jinwolee          #+#    #+#             */
/*   Updated: 2021/05/17 15:38:46 by jinwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cnt;

	if (!lst)
		return (0);
	i = 1;
	cnt = lst->next;
	while (cnt)
	{
		i++;
		cnt = cnt->next;
	}
	return (i);
}
