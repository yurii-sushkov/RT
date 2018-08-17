/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:22:01 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:26:03 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int min_fix[2];

	min_fix[0] = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putnbr_fd(n / 10, fd);
	}
	if (min_fix[0])
	{
		ft_putchar_fd('0' + n % 10, fd);
		n = min_fix[1];
	}
	ft_putchar_fd('0' + n % 10, fd);
}
