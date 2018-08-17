/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:24:05 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/29 14:33:08 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	if ((!src && !dst) || n == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	while (n > 0)
	{
		n--;
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
