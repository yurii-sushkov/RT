/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:47:13 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:00:39 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*find_intersection_part_2(t_ray *ray, t_obj *obj, double *t)
{
	if (obj->type == 4)
	{
		if ((*t = intersect_cone(ray, obj)))
			return (obj);
	}
	else if (obj->type == 5)
	{
		if ((*t = intersect_disk(ray, obj)))
			return (obj);
	}
	else if (obj->type == 6)
	{
		if ((*t = intersect_box(ray, obj)))
			return (obj);
	}
	return (0);
}

t_obj	*find_intersection(t_ray *ray, t_obj *obj, double *t)
{
	if (obj->type == 1)
	{
		if ((*t = intersect_sphere(ray, obj)))
			return (obj);
	}
	else if (obj->type == 2)
	{
		if ((*t = intersect_plane(ray, obj)))
			return (obj);
	}
	else if (obj->type == 3 && obj->length > 0)
	{
		if ((*t = intersect_finite_cylinder(ray, obj)))
			return (obj);
	}
	else if (obj->type == 3)
	{
		if ((*t = intersect_cylinder(ray, obj)))
			return (obj);
	}
	return (find_intersection_part_2(ray, obj, t));
}

t_obj	*intersect(t_data *d, t_ray *ray, double *t)
{
	t_obj	*found;
	t_obj	*i;
	double	t_nearest;
	t_obj	*obj_nearest;

	obj_nearest = 0;
	t_nearest = 0;
	i = d->obj;
	while (i)
	{
		found = find_intersection(ray, i, t);
		if (*t > 0)
		{
			if (!t_nearest || *t < t_nearest)
			{
				t_nearest = *t;
				obj_nearest = found;
			}
		}
		i = i->next;
	}
	*t = t_nearest;
	return (obj_nearest);
}
