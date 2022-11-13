/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:16:07 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:44:19 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"

int	cmp_overflow(char *str, int sign)
{
	int		i;
	char	*overflow;

	i = 0;
	if (sign == -1)
		overflow = "-2147483648";
	else
		overflow = "2147483647";
	while (str[i] == overflow[i] && str[i])
		i++;
	if (str[i] <= overflow[i])
		return (0);
	return (1);
}

int	check_int_overflow(char *str)
{
	int	len;
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (0);
	if (len == 10)
	{
		if (str[0] == '-')
		{
			if (cmp_overflow(str, -1))
				return (0);
		}
		else
		{
			if (cmp_overflow(str, 1))
				return (0);
		}
	}
	return (1);
}
