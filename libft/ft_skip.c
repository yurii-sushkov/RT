/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:31:55 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:38:20 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_skip(char **str, char c)
{
	unsigned int	skipped;

	if (!str)
		return (0);
	if (*str == NULL)
		return (0);
	skipped = 0;
	while (**str == c)
	{
		(*str)++;
		skipped++;
	}
	return (skipped);
}
