/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:18:31 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 14:59:43 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	reset_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->a = 0;
}

void	cap_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->g > 255)
		color->g = 255;
	if (color->g < 0)
		color->g = 0;
	if (color->b > 255)
		color->b = 255;
	if (color->b < 0)
		color->b = 0;
}

void	mul_color(t_color *col, double k)
{
	if (col)
	{
		col->r *= k;
		col->g *= k;
		col->b *= k;
		cap_color(col);
	}
}

int		rgb_to_int(int r, int g, int b)
{
	int	result;

	result = 0;
	result += b;
	result += g * 256;
	result += r * 65536;
	return (result);
}
