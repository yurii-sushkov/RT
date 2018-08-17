/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:07:39 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:00:16 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	intersect_disk(t_ray *ray, t_obj *disk)
{
	double	t;
	t_vec3f	p;

	if (!(t = intersect_plane(ray, disk)))
		return (0);
	get_intersection_point(ray, t, &p);
	p.x -= disk->pos.x;
	p.y -= disk->pos.y;
	p.z -= disk->pos.z;
	if (vec3len(p) <= disk->scale.x)
		return (t);
	return (0);
}
