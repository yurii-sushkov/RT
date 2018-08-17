/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:23:17 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:36:09 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;
	char			*strp;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	strp = str;
	index = 0;
	while (*strp != '\0')
	{
		*strp = f(index, *strp);
		strp++;
		index++;
	}
	return (str);
}
