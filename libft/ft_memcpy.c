/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:11:49 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/01 13:01:29 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	const char		*sr;

	ds = dst;
	sr = src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
