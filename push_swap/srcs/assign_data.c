/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:36:44 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 13:54:50 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"
#include <limits.h>

void	assign_pos(t_stack *stack)
{
	int		pos;
	t_stack	*ptr;

	pos = 0;
	ptr = stack;
	while (ptr)
	{
		ptr->pos = pos++;
		ptr = ptr->next;
	}
}

void	assign_index(t_stack *stack, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (size-- > 0)
	{
		ptr = stack;
		highest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size + 1;
	}
}

void	assign_data(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	assign_index(*a, size);
	if (is_a_sorted(*a))
		return ;
	init_sort(a, b, size);
	sort_center(a, b, size);
}
