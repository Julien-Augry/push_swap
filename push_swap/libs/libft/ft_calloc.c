/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:27:07 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 16:12:51 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	p = malloc(size * count);
	if (!(p))
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}
