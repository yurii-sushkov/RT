/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:51:42 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:01:30 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	intersect_plane(t_ray *ray, t_obj *plane)
{
	double	d;
	double	t;
	t_vec3f	vec;

	d = dot_product(&(plane->direction), &(ray->direction));
	if (d > 0.0000001 || d < 0.0000001)
	{
		vec.x = plane->pos.x - ray->origin.x;
		vec.y = plane->pos.y - ray->origin.y;
		vec.z = plane->pos.z - ray->origin.z;
		t = dot_product(&(plane->direction), &vec) / d;
		if (t == 0)
			t = 0.000001;
		if (t > 0)
			return (t);
	}
	return (0);
}
