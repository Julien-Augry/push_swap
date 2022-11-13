/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:59:45 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 18:20:36 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	rotate_a(t_stack **a, int rr)
{
	t_stack	*last;
	t_stack	*ptr;

	if (!a)
		return ;
	ptr = *a;
	*a = (*a)->next;
	last = last_node(*a);
	ptr->next = NULL;
	last->next = ptr;
	if (rr == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **b, int rr)
{
	t_stack	*last;
	t_stack	*ptr;

	if (!b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	last = last_node(*b);
	ptr->next = NULL;
	last->next = ptr;
	if (rr == 0)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	ft_putstr_fd("rr\n", 1);
}
