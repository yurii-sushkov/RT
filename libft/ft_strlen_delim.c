/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_delim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:12:22 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:03:42 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_delim(const char *s, char delim)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s != '\0' && *s != delim)
	{
		len++;
		s++;
	}
	return (len);
}
