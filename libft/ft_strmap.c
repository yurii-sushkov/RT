/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:02:06 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:35:59 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*strp;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	strp = str;
	while (*strp != '\0')
	{
		*strp = f(*strp);
		strp++;
	}
	return (str);
}
