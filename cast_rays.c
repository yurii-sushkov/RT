/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:06:07 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 12:46:21 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Эта функция вызывается для каждого пикселя,
**	И для каждого пикселя создается отдельная структура t_cast
*/

int		cast_primary_ray(t_data *d, int x, int y)
{
	t_cast	c;

	c.d = d;
	c.depth = d->max_depth;
	c.ray.origin.x = d->cam.pos.x;
	c.ray.origin.y = d->cam.pos.y;
	c.ray.origin.z = d->cam.pos.z;
	c.ray.direction = pixel_to_point(d, x, y);
	normalize(&(c.ray.direction));
	c.closest_obj = intersect(d, &(c.ray), &(c.t));
	reset_color(&(c.col));
	shadow_ray(&c);
	if (d->speed_mode)
	{
		putpixel(&(d->win), &(d->img), vec2(x, y), c.col);
		putpixel(&(d->win), &(d->img), vec2(x + 1, y), c.col);
		putpixel(&(d->win), &(d->img), vec2(x, y + 1), c.col);
		putpixel(&(d->win), &(d->img), vec2(x + 1, y + 1), c.col);
	}
	else
		putpixel(&(d->win), &(d->img), vec2(x, y), c.col);
	return (1);
}

void	*loop(void *t)
{
	int	x;
	int	y;

	x = 0;
	while (x < (((t_thread *)t)->data)->win.size.x)
	{
		if ((((t_thread *)t)->data)->speed_mode)
			y = ((t_thread *)t)->id * 2;
		else
			y = ((t_thread *)t)->id;
		while (y < (((t_thread *)t)->data)->win.size.y)
		{
			cast_primary_ray((((t_thread *)t)->data), x, y);
			if ((((t_thread *)t)->data)->speed_mode)
				y += (((t_thread *)t)->data)->threads
					+ (((t_thread *)t)->data)->threads;
			else
				y += (((t_thread *)t)->data)->threads;
		}
		if ((((t_thread *)t)->data)->speed_mode)
			x += 2;
		else
			x++;
	}
	return (t);
}

int		iterate_pixels(t_data *d)
{
	pthread_t	threads[d->threads];
	int			i;
	t_thread	thread_ids[d->threads];

	i = 0;
	while (i < d->threads)
	{
		(thread_ids[i]).data = d;
		(thread_ids[i]).id = i;
		i++;
	}
	i = 0;
	while (i < d->threads)
	{
		pthread_create(&(threads[i]), NULL, loop, &(thread_ids[i]));
		i++;
	}
	i = 0;
	while (i < d->threads)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (1);
}
