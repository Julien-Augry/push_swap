/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:52:30 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:53:17 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	is_a_sorted(t_stack *a)
{
	t_stack	*ptr;
	int		num;
	int		size;

	ptr = a;
	num = 0;
	size = stack_size(a);
	while (ptr && size > 1)
	{
		num = (int)ptr->value;
		ptr = ptr->next;
		size --;
		if ((int)ptr->value < num)
			return (0);
	}
	return (1);
}
