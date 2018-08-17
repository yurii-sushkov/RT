/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:15:38 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:14:46 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->content_size = content_size;
	if (content == 0)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = (void *)malloc(content_size);
		ft_memcpy(link->content, content, content_size);
	}
	link->next = NULL;
	return (link);
}
