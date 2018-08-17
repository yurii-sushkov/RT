/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:42:21 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:35:35 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	char	*last_occurence;

	to_find = (char)c;
	last_occurence = NULL;
	while (*s != '\0')
	{
		if (*s == to_find)
			last_occurence = (char *)s;
		s++;
	}
	if (*s == to_find)
		return ((char *)s);
	return (last_occurence);
}
