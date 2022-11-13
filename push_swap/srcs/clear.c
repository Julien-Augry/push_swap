/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:44:20 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 18:20:12 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*next;

	ptr = *stack;
	next = NULL;
	if (stack)
	{
		while (ptr)
		{
			next = ptr->next;
			free(ptr);
			ptr = next;
		}
		*stack = NULL;
	}
}
