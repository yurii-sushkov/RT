/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:02:14 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 16:39:31 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	const char		*src;
	char			*dest;

	if (!s)
		return (NULL);
	src = s;
	start = 0;
	start = ft_skip_whitespaces((char **)&s);
	len = ft_strlen(s);
	if (len > 0)
	{
		s += len - 1;
		len -= ft_rskip_whitespaces((char **)&s);
	}
	dest = ft_strsub(src, start, len);
	return (dest);
}
