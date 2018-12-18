/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:32:58 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/15 10:24:07 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*nxt;

	if ((*alst == NULL) || (del == NULL))
		return ;
	while (*alst)
	{
		nxt = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = nxt;
	}
}
