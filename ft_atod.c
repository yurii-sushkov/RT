/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:12:49 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/29 13:31:25 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_fraction(double result, const char *str)
{
	double	div;

	div = 1;
	str++;
	while (*str != '\0' && *str >= '0' && *str <= '9' && div * 10 > 0)
	{
		div *= 10;
		result += (double)(*str - '0') / div;
		str++;
	}
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str != '.' && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (double)(*str - '0');
		str++;
	}
	if (*str == '.')
		result = get_fraction(result, str);
	result *= sign;
	return (result);
}
