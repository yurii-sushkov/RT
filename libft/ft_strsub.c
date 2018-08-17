/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:41:26 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 16:39:26 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*pdest;

	if (!s)
		return (NULL);
	s += start;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	pdest = dest;
	while (len-- > 0)
		*(pdest++) = *(s++);
	*pdest = '\0';
	return (dest);
}
