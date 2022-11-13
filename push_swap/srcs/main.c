/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:23:39 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:50:48 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (-1);
	if (!(args_to_stack(av, ac, &a)))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!parse_stack(a))
	{
		clear_stack(&a);
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	assign_data(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (1);
}
