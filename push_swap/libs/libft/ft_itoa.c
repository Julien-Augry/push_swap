/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:53:31 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 16:39:19 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_itoaw(char *s, long long int n, int l, int neg)
{
	int	i;

	i = l - 1;
	while (n > 9)
	{
		s[i--] = n % 10 + '0';
		n = n / 10;
	}
	s[i--] = n + '0';
	if (neg == 1)
		s[i--] = '-';
	s[l] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	long long int	nu;
	int				neg;
	int				l;
	char			*s;
	long long int	num;

	num = n;
	neg = 0;
	if (num < 0)
	{
		num = -num;
		neg = 1;
	}
	l = 1 + neg;
	nu = num;
	while (nu > 9)
	{
		nu = nu / 10;
		l++;
	}
	s = malloc(sizeof(char) * (l + 1));
	if (!(s))
		return (NULL);
	s = ft_itoaw(s, num, l, neg);
	return (s);
}
