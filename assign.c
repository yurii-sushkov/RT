/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:44:28 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 14:59:09 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void	assign_double(double *dest, char *str)
{
	if (!str)
		ft_error("Error: missing value in a parameter.");
	*dest = ft_atod(str);
}

void	assign_deg(double *dest, char *str)
{
	if (!str)
		ft_error("Error: missing value in a parameter.");
	*dest = ft_atod(str) * DEG;
}

void	assign_int(int *dest, char *str)
{
	if (!str)
		ft_error("Error: missing value in a parameter.");
	*dest = ft_atoi(str);
}
