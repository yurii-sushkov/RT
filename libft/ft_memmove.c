/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:40:34 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/29 14:24:41 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overlap(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (dst == src)
			return (1);
		src++;
		i++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if ((!dst && !src) || src == dst)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (overlap(dst, src, len))
	{
		i = len;
		while (--i > 0)
			d[i] = s[i];
		d[0] = s[0];
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
