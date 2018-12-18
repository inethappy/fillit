/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:32:49 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 18:37:07 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizech(int i)
{
	int c;

	c = 1;
	if (i < 0)
		c++;
	while (i /= 10)
		c++;
	return (c);
}

char		*ft_itoa(int i)
{
	char	*res;
	int		j;
	int		sign;

	j = 0;
	sign = 1;
	if ((res = (char*)malloc(sizeof(char) * (ft_sizech(i) + 1))) == NULL)
		return (NULL);
	ft_bzero(res, ft_sizech(i) + 1);
	if (i < 0)
		sign = -1;
	if (i == 0)
		res[j++] = '0';
	while (i)
	{
		res[j++] = ft_abs(i % 10) + 48;
		i = i / 10;
	}
	if (sign == -1)
		res[j++] = '-';
	return (ft_str_rev(res));
}
