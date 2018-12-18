/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:38:44 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 13:22:03 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start + i];
	return (res);
}
