/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:30:24 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:11:33 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**delete(char **arr)
{
	char	**temp;

	temp = arr;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(arr);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int		word_count;
	char				**arr;
	char				**result;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, (int)c);
	arr = (char **)malloc(word_count * sizeof(char *) + 1);
	if (arr == NULL)
		return (NULL);
	result = arr;
	while (word_count-- > 0)
	{
		ft_skip((char **)&s, c);
		*arr = ft_strndup(s, ft_strlen_delim(s, c));
		if (!(*arr))
			return (delete(result));
		while (*s != '\0' && *s != c)
			s++;
		arr++;
	}
	*arr = 0;
	return (result);
}
