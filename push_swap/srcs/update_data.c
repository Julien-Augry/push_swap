/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:40:13 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/23 13:31:07 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	get_higher(t_stack *stack)
{
	int		higher;
	t_stack	*ptr;

	higher = 0;
	ptr = stack;
	while (ptr)
	{
		if (ptr->index > higher)
			higher = ptr->index;
		ptr = ptr->next;
	}
	return (higher);
}

int	get_lower(t_stack *a, int size)
{
	t_stack	*ptr;
	int		lower;

	ptr = a;
	while (ptr)
	{
		if (ptr->index < size)
		{
			size = ptr->index;
			lower = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (lower);
}

int	get_target(t_stack *a, int index, int size)
{
	t_stack	*ptr;
	int		target;

	target = get_lower(a, size);
	ptr = a;
	if (ptr->index > get_higher(a))
		return (target);
	while (ptr)
	{
		if (ptr->index > index && ptr->index <= size)
		{
			size = ptr->index;
			target = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (target);
}

void	assign_target(t_stack **a, t_stack **b, int size)
{
	t_stack	*ptr_b;
	int		target;

	ptr_b = *b;
	while (ptr_b)
	{
		target = get_target(*a, ptr_b->index, size);
		ptr_b->target = target;
		ptr_b = ptr_b->next;
	}
}

void	update_data(t_stack **a, t_stack **b, int size)
{
	assign_pos(*a);
	assign_pos(*b);
	assign_target(a, b, size);
	assign_cost(a, b);
}
