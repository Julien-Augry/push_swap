/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:27:56 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 16:21:24 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;

	if (!dst && !src)
		return (NULL);
	p1 = (char *)src;
	p2 = (char *)dst;
	while (n > 0)
	{
		p2[n - 1] = p1[n - 1];
		n--;
	}
	return (dst);
}
