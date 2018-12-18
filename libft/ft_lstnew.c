/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:45:50 by okuchko           #+#    #+#             */
/*   Updated: 2018/11/14 13:45:59 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*con;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if ((con = (void*)malloc(sizeof(*content) * content_size)) == NULL)
			return (NULL);
		ft_memcpy(con, content, content_size);
		new->content = con;
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
