/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 07:23:55 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:35:09 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(const char *haystack, const char *needle)
{
	char	*solution;

	if (*haystack == *needle)
	{
		solution = ((char *)haystack);
		while (*needle != '\0')
		{
			if (*(haystack++) != *(needle++))
				solution = NULL;
		}
		if (solution != NULL)
			return (solution);
	}
	return (NULL);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char		*solution;

	solution = NULL;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			solution = check(haystack, needle);
			if (solution != NULL)
				return (solution);
		}
		haystack++;
	}
	return (solution);
}
