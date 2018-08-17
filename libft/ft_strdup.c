/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:29:41 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:07:57 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*p;
	int		len;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	p = dest;
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = '\0';
	return (dest);
}
