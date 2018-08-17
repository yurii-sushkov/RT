/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:04:28 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:01:22 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3f	pixel_to_point(t_data *d, int x, int y)
{
	t_vec3f	point;
	double	aspect_ratio;
	double	up;
	double	right;

	aspect_ratio = (double)d->win.size.x / (double)d->win.size.y;
	point.x = d->cam.direction.x;
	point.y = d->cam.direction.y;
	point.z = d->cam.direction.z;
	right = (((double)x + 0.5) / d->win.size.x) - 0.5;
	right *= aspect_ratio;
	up = 0.5 - (((double)y + 0.5) / d->win.size.y);
	point.x += d->cam.right.x * right;
	point.y += d->cam.right.y * right;
	point.z += d->cam.right.z * right;
	point.x += d->cam.up.x * up;
	point.y += d->cam.up.y * up;
	point.z += d->cam.up.z * up;
	return (point);
}
