/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:57:35 by ibarabas          #+#    #+#             */
/*   Updated: 2018/05/08 11:57:36 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	if (!lst)
		return (NULL);
	while (index > 0)
	{
		if (!(lst->next))
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}
