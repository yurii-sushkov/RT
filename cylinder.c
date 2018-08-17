/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:51:56 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:00:07 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	intersect_cylinder(t_ray *ray, t_obj *cyl)
{
	double	a;
	double	b;
	double	c;
	double	t[2];
	t_ray	r;

	r = transform_ray(ray, cyl);
	a = r.direction.x * r.direction.x
		+ r.direction.z * r.direction.z;
	b = 2 * r.origin.x * r.direction.x
		+ 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x
		+ r.origin.z * r.origin.z - 1;
	if (!quadratic_equation(a, b, c, t))
		return (0);
	return (closest(t));
}

/*
**	Диски находятся на концах конечного цилиндра.
*/

void	make_disk(t_ray *r, t_obj *disk, t_obj *cyl)
{
	disk->pos.x = 0;
	if (r->origin.y > 0)
		disk->pos.y = cyl->length;
	else
		disk->pos.y = -cyl->length;
	disk->pos.z = 0;
	disk->direction.x = 0;
	disk->direction.y = 1;
	disk->direction.z = 0;
	disk->scale.x = 1;
	disk->scale.y = 1;
	disk->scale.z = 1;
}

double	intersect_finite_cylinder(t_ray *ray, t_obj *cyl)
{
	double	t[2];
	t_vec3f	p;
	t_ray	r;
	t_obj	disk;

	t[0] = intersect_cylinder(ray, cyl);
	r = transform_ray(ray, cyl);
	get_intersection_point(&r, t[0], &p);
	make_disk(&r, &disk, cyl);
	t[1] = intersect_disk(&r, &disk);
	if (t[1] && t[1] < t[0])
		return (t[1]);
	if (p.y > cyl->length || p.y < -cyl->length)
	{
		if (t[1])
			return (t[1]);
		return (0);
	}
	return (t[0]);
}
