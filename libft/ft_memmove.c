/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:46:19 by okuchko           #+#    #+#             */
/*   Updated: 2018/10/31 18:40:58 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	const char	*sr;

	ds = dst;
	sr = src;
	if (src > dst)
	{
		while (len--)
			*(ds++) = *(sr++);
	}
	else
	{
		while (len--)
			ds[len] = sr[len];
	}
	return (dst);
}
