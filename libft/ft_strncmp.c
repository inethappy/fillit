/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:12:37 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 10:11:21 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && s1[i] && s2[i] &&
			((((unsigned char*)s1)[i]) == (((unsigned char*)s2)[i])))
		i++;
	if (i == n)
		i--;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
