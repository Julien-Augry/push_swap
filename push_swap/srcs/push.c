/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:59:38 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/14 15:48:47 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	*next;

	if (!a)
		return ;
	ptr = *a;
	next = ptr->next;
	add_node(b, new_node(ptr->value, ptr->index));
	free(*a);
	*a = next;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_stack **b, t_stack **a)
{
	t_stack	*ptr;
	t_stack	*next;

	if (!b)
		return ;
	ptr = *b;
	next = ptr->next;
	add_node(a, new_node(ptr->value, ptr->index));
	free(*b);
	*b = next;
	ft_putstr_fd("pa\n", 1);
}
