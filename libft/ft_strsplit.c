/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:31:12 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 13:49:17 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlench(char const *s, char c)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_ncwords(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s && s[0])
	{
		while (s[i])
		{
			if (s[i] == c)
				i++;
			else
			{
				words++;
				i += ft_strlench(&s[i], c);
			}
		}
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	if ((res = (char**)malloc(sizeof(char*) * (ft_ncwords(s, c) + 1))) == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c)
			i++;
		else
		{
			if ((res[++j] = ft_strsub(s, i, ft_strlench(&s[i], c))) != NULL)
				i += ft_strlench(&s[i], c);
			else
				return (NULL);
		}
	}
	res[j + 1] = NULL;
	return (res);
}
