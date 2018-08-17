/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:18:06 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:08:28 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*origin;

	origin = dst;
	while (*src != '\0' && len > 0)
	{
		*(dst++) = *(src++);
		len--;
	}
	while (len > 0)
	{
		*(dst++) = '\0';
		len--;
	}
	return (origin);
}
