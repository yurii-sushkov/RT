/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:14:12 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:03:49 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*dest;
	char		*p;
	size_t		len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	dest = (char *)malloc(len + 1);
	p = dest;
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0' && len-- > 0)
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = '\0';
	return (dest);
}
