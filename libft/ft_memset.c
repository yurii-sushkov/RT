/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:39:39 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 08:55:43 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	char			*p;

	p = (char *)b;
	uc = (unsigned char)c;
	while (len > 0)
	{
		*p = uc;
		p++;
		len--;
	}
	return (b);
}
