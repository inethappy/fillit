/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:43:29 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 18:05:06 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = 10 * res + str[i] - 48;
		i++;
	}
	if ((res >= 9223372036854775807) && (sign == 1))
		return (-1);
	if ((res >= 9223372036854775807) && (sign == -1))
		return (0);
	return (sign * res);
}
