/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:33:30 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 14:26:13 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*out;

	if ((lst == NULL) || (f == NULL))
		return (NULL);
	if ((out = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
		return (NULL);
	res = out;
	while (lst->next)
	{
		lst = lst->next;
		out->next = f(lst);
		out = out->next;
	}
	return (res);
}
