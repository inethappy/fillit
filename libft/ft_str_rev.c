/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:35:16 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 14:35:34 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rev(char *s)
{
	int		i;
	int		len;
	char	tmp;

	if (s)
	{
		i = 0;
		len = ft_strlen(s) - 1;
		while ((i < len) && s[i] && s[len])
		{
			tmp = s[i];
			s[i] = s[len];
			s[len] = tmp;
			i++;
			len--;
		}
	}
	return (s);
}
