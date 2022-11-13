/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:40:38 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 18:18:07 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	add_node(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

t_stack	*before_last_node(t_stack *stack)
{
	if (stack)
		while (stack->next->next)
			stack = stack->next;
	return (stack);
}

t_stack	*last_node(t_stack *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

t_stack	*new_node(int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->index = index;
		new->next = NULL;
	}
	return (new);
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*ptr;

	ptr = stack;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
