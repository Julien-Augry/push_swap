/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:32:32 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 16:49:01 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dstlen;
	size_t		srclen;
	int			x;

	x = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (srclen + size);
	while ((dstlen + x + 1) < size && src[x] != '\0')
	{
		dst[x + dstlen] = src[x];
		x++;
	}
	dst[x + dstlen] = '\0';
	return (dstlen + srclen);
}
