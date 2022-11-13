/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:44:45 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/23 14:23:03 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	rush_b(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = size;
	while (i > (size / 2) + 1)
	{
		if ((*a)->index <= (size / 2))
		{
			push_b(a, b);
			i--;
		}
		else
			rotate_a(a, 0);
	}
	while (i > 3)
	{
		push_b(a, b);
		i--;
	}
}

void	sort_three(t_stack **a)
{
	if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		rotate_a(a, 0);
	else if ((*a)->next->index > (*a)->next->next->index)
		reverse_a(a, 0);
	if ((*a)->index > (*a)->next->index)
		swap_a(*a, 0);
}

void	init_sort(t_stack **a, t_stack **b, int size)
{
	if (!(is_a_sorted(*a)))
	{
		if (size == 2)
			swap_a(*a, 0);
		else if (size == 3)
			sort_three(a);
	}
	if (!(is_a_sorted(*a)))
		rush_b(a, b, size);
	if (!(is_a_sorted(*a)))
		sort_three(a);
}
