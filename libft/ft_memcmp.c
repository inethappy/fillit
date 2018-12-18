/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:27:14 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 16:24:54 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while ((i < n) && (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]))
		i++;
	if (i == n)
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
