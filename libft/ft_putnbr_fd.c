/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:37:40 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/09 17:58:59 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_f(int i, int fd)
{
	if (i != 0)
	{
		ft_f(i / 10, fd);
		ft_putchar_fd(48 + ft_abs(i % 10), fd);
		return (0);
	}
	else
		return (0);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_f(n, fd);
}
