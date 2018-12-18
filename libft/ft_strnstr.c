/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:59:57 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 10:12:34 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len_n;
	size_t len_h;
	size_t i;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	len_n = ft_strlen((char*)needle);
	len_h = ft_strlen((char*)haystack);
	if (len_n > len)
		return (NULL);
	while ((i <= (len_h - len_n - len)) && (haystack[i]))
	{
		if (!ft_strncmp(&haystack[i], needle, len_n))
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
