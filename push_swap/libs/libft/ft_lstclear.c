/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:20:29 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 16:15:56 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	next = NULL;
	if (lst && del)
	{
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = next;
		}
		*lst = NULL;
	}
}
