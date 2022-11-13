/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:07:26 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:41:20 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nu;

	nu = n;
	if (nu < 0)
	{
		ft_putchar_fd('-', fd);
		nu = -nu;
	}
	if (nu > 9)
		ft_putnbr_fd(nu / 10, fd);
	ft_putchar_fd(nu % 10 + '0', fd);
}
