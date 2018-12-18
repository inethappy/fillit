/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_len_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:55:54 by mkotytsk          #+#    #+#             */
/*   Updated: 2018/11/13 13:55:58 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_len_n(const char *s, char c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
