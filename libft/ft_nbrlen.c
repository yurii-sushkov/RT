/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:23:45 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 16:31:29 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr)
{
	size_t	nbrlen;

	nbrlen = 1;
	if (nbr < 0)
		nbrlen++;
	while (nbr / 10 != 0)
	{
		nbrlen++;
		nbr /= 10;
	}
	return (nbrlen);
}
