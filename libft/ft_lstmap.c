/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:43:14 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 13:12:10 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
		free(content);
}

static t_list	*lstcopy(t_list *lst)
{
	t_list	*list;
	t_list	*prev;

	list = ft_lstnew(lst->content, lst->content_size);
	if (!list)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		prev = list;
		ft_lstadd(&list, ft_lstnew(lst->content, lst->content_size));
		if (!list)
		{
			ft_lstdel(&prev, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (list);
}

static t_list	*apply(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;

	if (!(result = f(list)))
		return (NULL);
	temp = list;
	list = list->next;
	if (temp)
		free(temp);
	while (list != NULL)
	{
		temp = result;
		ft_lstadd(&result, f(list));
		if (!result)
		{
			ft_lstdel(&temp, del);
			ft_lstdel(&list, del);
			return (NULL);
		}
		temp = list;
		list = list->next;
		if (temp)
			free(temp);
	}
	return (result);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	list = lstcopy(lst);
	if (!list)
		return (NULL);
	result = apply(list, f);
	if (!result)
		return (NULL);
	return (result);
}
