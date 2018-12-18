/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:32:41 by okuchko           #+#    #+#             */
/*   Updated: 2018/12/06 18:01:14 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		if (!(res = ft_strnew(ft_strlen(s2))))
			return (NULL);
		return (res = ft_strcpy(res, s2));
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((res = ft_strnew(l1 + l2)) == NULL)
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}
