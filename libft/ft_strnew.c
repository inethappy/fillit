/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:05:17 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 11:07:07 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *this;

	if ((this = ft_memalloc(size + 1)) != NULL)
	{
		ft_bzero((void*)this, size + 1);
		return (this);
	}
	return (NULL);
}
