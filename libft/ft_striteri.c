/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:38:37 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 18:35:39 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*tmp;
	unsigned int	i;

	if (s && s[0] && f)
	{
		i = 0;
		tmp = s;
		while (tmp[i])
		{
			f(i, &tmp[i]);
			i++;
		}
	}
}
