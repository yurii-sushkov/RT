/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:18:59 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 09:00:33 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_negative(int n)
{
	if (n == -2147483648)
		return (2);
	else if (n < 0)
		return (1);
	else
		return (0);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		negative;

	len = ft_nbrlen(n);
	negative = is_negative(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (negative == 2)
		n = 147483648;
	else if (negative == 1)
		n = -n;
	*(str++) = '0' + (n % 10);
	while (n / 10 > 0)
	{
		n /= 10;
		*(str++) = '0' + (n % 10);
	}
	if (negative == 2)
		*(str++) = '2';
	if (negative)
		*(str++) = '-';
	return (ft_strrev(str - len));
}
