/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:16:09 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 13:43:14 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if ((lst == NULL) || (f == NULL))
		return ;
	while (lst->next)
	{
		f(lst);
		lst = lst->next;
	}
	f(lst);
}
