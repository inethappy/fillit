/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:07:04 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/09 16:51:00 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_f(int i)
{
	if (i != 0)
	{
		ft_f(i / 10);
		ft_putchar(48 + ft_abs(i % 10));
		return (0);
	}
	else
		return (0);
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
		ft_putchar('-');
	ft_f(n);
}
