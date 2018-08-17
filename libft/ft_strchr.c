/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:17:10 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:35:25 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = (char)c;
	while (*s != '\0')
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	if (*s == to_find)
		return ((char *)s);
	return (NULL);
}
