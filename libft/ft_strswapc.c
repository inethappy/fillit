/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswapc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:34:41 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 18:51:04 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strswapc(char *s, char src, char dst)
{
	char	*tmp;

	if ((s == NULL) || (dst == '\0') || src == '\0')
		return (s);
	tmp = s;
	while (*tmp)
	{
		if ((*tmp) == src)
			(*tmp) = dst;
		tmp++;
	}
	return (s);
}
