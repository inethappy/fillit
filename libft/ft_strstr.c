/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:02:58 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 18:19:06 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len_n;
	int len_h;
	int i;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	len_n = ft_strlen((char*)needle);
	len_h = ft_strlen((char*)haystack);
	while (i <= (len_h - len_n))
	{
		if ((ft_strncmp(&haystack[i], needle, len_n)) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
