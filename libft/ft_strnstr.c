/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 07:40:33 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 07:43:45 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(const char *haystack, const char *needle, size_t len)
{
	char	*solution;

	if (*haystack == *needle)
	{
		solution = (char *)haystack;
		while (*needle != '\0' && *haystack != '\0' && len > 0)
		{
			if (*(haystack++) != *(needle++))
				solution = NULL;
			if (*haystack == '\0' && *needle != '\0')
				solution = NULL;
			len--;
		}
		if (len == 0 && *needle != '\0')
			solution = NULL;
		if (solution != NULL)
			return (solution);
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*solution;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			solution = check(haystack, needle, len);
			if (solution != NULL)
				return (solution);
		}
		len--;
		haystack++;
	}
	return (NULL);
}
