/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:37:17 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:26:15 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int min_fix[2];

	min_fix[0] = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		if (n < 0)
		{
			min_fix[0] = 1;
			min_fix[1] = -(n % 10);
			n = -(n / 10);
		}
	}
	if (n / 10 > 0)
	{
		ft_putnbr(n / 10);
	}
	if (min_fix[0])
	{
		ft_putchar('0' + n % 10);
		n = min_fix[1];
	}
	ft_putchar('0' + n % 10);
}
