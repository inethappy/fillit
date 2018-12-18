/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:40:48 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/01 11:24:00 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sr;

	i = 0;
	sr = (unsigned char*)src;
	while ((i < n) && (sr[i] != (unsigned char)c))
		i++;
	if (i != n)
	{
		ft_memcpy(dst, src, i + 1);
		return (&dst[i + 1]);
	}
	else
		ft_memcpy(dst, src, n);
	return (NULL);
}
