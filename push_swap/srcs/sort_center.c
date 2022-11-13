/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:40:30 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 19:00:32 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	moulinette(t_stack **stack)
{
	int		blend;
	int		reverse;
	t_stack	*ptr;

	ptr = *stack;
	blend = 0;
	reverse = 0;
	while (ptr->index != 1)
	{
		blend++;
		ptr = ptr->next;
	}
	if (blend >= stack_size(*stack) / 2)
	{
		blend = stack_size(*stack) - blend;
		reverse = 1;
	}
	while (blend > 0)
	{
		if (reverse == 1)
			reverse_a(stack, 0);
		else
			rotate_a(stack, 0);
		blend--;
	}
}

void	target_push2(t_stack **a, t_stack **b, t_stack *ptr)
{
	while (ptr->cost_a > 0)
	{
		rotate_a(a, 0);
		ptr->cost_a--;
	}
	while (ptr->cost_a < 0)
	{
		reverse_a(a, 0);
		ptr->cost_a++;
	}
	while (ptr->cost_b > 0)
	{
		rotate_b(b, 0);
		ptr->cost_b--;
	}
	while (ptr->cost_b < 0)
	{
		reverse_b(b, 0);
		ptr->cost_b++;
	}
}

void	target_push(t_stack **a, t_stack **b, int move)
{
	t_stack	*ptr;

	ptr = *b;
	while (ptr->pos != move)
		ptr = ptr->next;
	while (ptr->cost_a > 0 && ptr->cost_b > 0)
	{
		rotate_both(a, b);
		ptr->cost_a--;
		ptr->cost_b--;
	}
	while (ptr->cost_a < 0 && ptr->cost_b < 0)
	{
		reverse_both(a, b);
		ptr->cost_a++;
		ptr->cost_b++;
	}
	target_push2(a, b, ptr);
	push_a(b, a);
}

void	sort_center(t_stack **a, t_stack **b, int size)
{
	int		move;
	int		size_b;

	move = 0;
	size_b = stack_size(*b);
	while (size_b > 0)
	{
		update_data(a, b, size);
		move = best_move(*b);
		target_push(a, b, move);
		size_b--;
	}
	moulinette(a);
}
