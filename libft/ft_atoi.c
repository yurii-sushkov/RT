/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:12:49 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/29 13:31:25 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (int)(*str - '0');
		if (result < 0 && sign > 0)
			return (-1);
		else if (result < 0 && sign < 0)
			return (0);
		str++;
	}
	result *= sign;
	return ((int)result);
}
