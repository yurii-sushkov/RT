/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:53:07 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 08:43:41 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	capacity;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize > dstlen + 1)
	{
		capacity = dstsize - dstlen - 1;
		dst += dstlen;
		while (*src != '\0' && capacity > 0)
		{
			*dst = *src;
			dst++;
			src++;
			capacity--;
		}
		*dst = '\0';
	}
	else if (dstlen > dstsize)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
