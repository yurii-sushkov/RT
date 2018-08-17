/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:44:22 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:03:22 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	with_whitespaces(char const *str)
{
	unsigned int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		ft_skip_whitespaces((char **)&str);
		if (*str != '\0' && !ft_iswhitespace(*str))
		{
			word_count++;
			while (*str != '\0' && !ft_iswhitespace(*str))
				str++;
		}
	}
	return (word_count);
}

static unsigned int	with_delimiter(char const *str, char delim)
{
	unsigned int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		ft_skip((char **)&str, delim);
		if (*str != '\0' && *str != delim)
		{
			word_count++;
			while (*str != '\0' && *str != delim)
				str++;
		}
	}
	return (word_count);
}

unsigned int		ft_count_words(char const *str, int delim)
{
	if (!str)
		return (0);
	if (delim == -1)
		return (with_whitespaces(str));
	else
		return (with_delimiter(str, (char)delim));
}
