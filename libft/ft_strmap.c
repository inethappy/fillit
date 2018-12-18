/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:47:27 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 12:39:40 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
