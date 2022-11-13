/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:08:59 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:51:41 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	check_doublon(t_stack *a, int nbr)
{
	t_stack	*ptr;
	int		i;

	ptr = a;
	i = 0;
	while (ptr)
	{
		if (ptr->value == nbr)
			i++;
		ptr = ptr->next;
	}
	if (i != 1)
		return (0);
	return (1);
}

int	parse_stack(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr)
	{
		if (!(check_doublon(a, ptr->value)))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
