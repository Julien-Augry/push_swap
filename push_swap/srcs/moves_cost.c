/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:07:49 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:53:36 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	best_move(t_stack *b)
{
	t_stack	*ptr;
	int		pos;
	int		moves_a;
	int		moves_b;
	int		best_move;

	ptr = b;
	best_move = stack_size(b);
	pos = 0;
	while (ptr)
	{
		moves_a = ptr->cost_a;
		moves_b = ptr->cost_b;
		if (ptr->cost_a < 0)
			moves_a = ptr->cost_a * -1;
		if (ptr->cost_b < 0)
			moves_b = ptr->cost_b * -1;
		if ((moves_a + moves_b) < best_move)
		{
			best_move = moves_a + moves_b;
			pos = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (pos);
}

int	get_cost(t_stack *stack, int pos)
{
	int	size;
	int	cost;

	cost = pos;
	size = stack_size(stack);
	if (pos > size / 2)
		cost = (size - pos) * -1;
	return (cost);
}

void	assign_cost(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *b;
	while (ptr)
	{
		ptr->cost_a = get_cost(*a, ptr->target);
		ptr->cost_b = get_cost(*b, ptr->pos);
		ptr = ptr->next;
	}
}
