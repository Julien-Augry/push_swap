/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:30:04 by juaugry           #+#    #+#             */
/*   Updated: 2019/11/11 15:13:17 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;
	const char	*lasts;
	char		*lastd;

	if (!dst && !src)
		return (NULL);
	pdst = dst;
	psrc = src;
	lasts = psrc + (len - 1);
	lastd = pdst + (len - 1);
	if (pdst < psrc)
		while (len--)
			*pdst++ = *psrc++;
	else
		while (len--)
			*lastd-- = *lasts--;
	return (dst);
}
