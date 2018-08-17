/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:55:06 by ibarabas          #+#    #+#             */
/*   Updated: 2018/05/21 08:20:32 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	putpixel(t_win *win, t_img *img, t_vec2 pos, t_color c)
{
	unsigned char	*p;

	if (pos.y >= 0 && pos.y < win->size.y &&
		pos.x >= 0 && pos.x < win->size.x)
	{
		p = (unsigned char *)(img->addr);
		p += pos.y * win->size.x * 4;
		p += pos.x * 4;
		if (img->endian == 0)
		{
			*p = c.b;
			*(p + 1) = c.g;
			*(p + 2) = c.r;
		}
		else
		{
			*p = c.r;
			*(p + 1) = c.g;
			*(p + 2) = c.b;
		}
		*(p + 3) = c.a;
	}
}

t_color	getpixel(t_win *win, t_img *img, int x, int y)
{
	t_color			color;
	unsigned char	*p;

	p = (unsigned char *)(img->addr);
	p += y * win->size.x * 4;
	p += x * 4;
	if (img->endian == 0)
	{
		color.b = *p;
		color.g = *(p + 1);
		color.r = *(p + 2);
	}
	else
	{
		color.r = *p;
		color.g = *(p + 1);
		color.b = *(p + 2);
	}
	color.a = *(p + 3);
	return (color);
}
