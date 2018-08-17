/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:14:43 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:24:29 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	to_find;

	str = (unsigned char *)s;
	to_find = c;
	while (n > 0)
	{
		if (*str == to_find)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
