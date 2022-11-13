/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:59:41 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:53:02 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	reverse_a(t_stack **a, int rrr)
{
	t_stack	*before_last;
	t_stack	*last;
	t_stack	*first;

	if (!a)
		return ;
	before_last = before_last_node(*a);
	last = last_node(*a);
	first = *a;
	*a = last;
	(*a)->next = first;
	before_last->next = NULL;
	if (rrr == 0)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_b(t_stack **b, int rrr)
{
	t_stack	*before_last;
	t_stack	*last;
	t_stack	*first;

	if (!b)
		return ;
	before_last = before_last_node(*b);
	last = last_node(*b);
	first = *b;
	*b = last;
	(*b)->next = first;
	before_last->next = NULL;
	if (rrr == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_both(t_stack **a, t_stack **b)
{
	reverse_a(a, 1);
	reverse_b(b, 1);
	ft_putstr_fd("rrr\n", 1);
}
