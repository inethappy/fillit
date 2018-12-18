/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:28:48 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 14:28:18 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	st;
	unsigned int	en;

	if (s == NULL)
		return (NULL);
	st = 0;
	while ((s[st] == ' ') || (s[st] == '\n') || (s[st] == '\t'))
		st++;
	if (s[st] == '\0')
		return (res = ft_strnew(0));
	en = ft_strlen(s) - 1;
	while ((s[en] == ' ') || (s[en] == '\n') || (s[en] == '\t'))
		en--;
	if (en >= st)
	{
		res = ft_strsub(s, st, en - st + 1);
		if (res)
			return (res);
	}
	return (NULL);
}
