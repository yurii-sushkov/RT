/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:45:24 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/30 10:52:29 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	char	delim;

	delim = (char)c;
	d = (char *)dst;
	s = (char *)src;
	while (n > 0)
	{
		*d = *s;
		if (*d == delim)
		{
			return ((void *)(d + 1));
		}
		d++;
		s++;
		n--;
	}
	return (NULL);
}
