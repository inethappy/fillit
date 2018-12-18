/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:18:17 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/02 19:10:19 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*this;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	this = (char*)malloc(sizeof(*s1) * (len + 1));
	if (this)
	{
		while (s1[i])
		{
			this[i] = s1[i];
			i++;
		}
		this[i] = '\0';
	}
	return (this);
}
