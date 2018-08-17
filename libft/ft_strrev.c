/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:13:34 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:03:56 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	buf;

	if (!str)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(str) - 1;
	while (start < end)
	{
		buf = str[start];
		str[start] = str[end];
		str[end] = buf;
		start++;
		end--;
	}
	return (str);
}
