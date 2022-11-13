/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:59:47 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 18:19:56 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	swap_a(t_stack *a, int ss)
{
	t_stack	*ptr;
	t_stack	*ptr2;
	int		value;
	int		index;

	if (!a)
		return ;
	ptr = a;
	ptr2 = ptr->next;
	if (ptr && ptr2)
	{
		value = ptr->value;
		index = ptr->index;
		ptr->value = ptr2->value;
		ptr->index = ptr2->index;
		ptr2->value = value;
		ptr2->index = index;
	}
	if (ss == 0)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *b, int ss)
{
	t_stack	*ptr;
	t_stack	*ptr2;
	int		value;
	int		index;

	if (!(b))
		return ;
	ptr = b;
	ptr2 = ptr->next;
	if (ptr && ptr2)
	{
		value = ptr->value;
		index = ptr->index;
		ptr->value = ptr2->value;
		ptr->index = ptr2->index;
		ptr2->value = value;
		ptr2->index = index;
	}
	if (ss == 0)
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap_a(*a, 1);
	swap_b(*b, 1);
	ft_putstr_fd("ss\n", 1);
}
