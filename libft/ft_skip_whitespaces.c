/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:15:28 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:02:21 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_skip_whitespaces(char **str)
{
	unsigned int	skipped;

	if (!str)
		return (0);
	if (*str == NULL)
		return (0);
	skipped = 0;
	while (ft_iswhitespace(**str))
	{
		(*str)++;
		skipped++;
	}
	return (skipped);
}
