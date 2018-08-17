/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:51:56 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:00:07 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Убеждается, что ближняя точка пересечения -
**	меньшее число, чем дальняя
*/

void	sort(t_vec3f *near, t_vec3f *far)
{
	double	temp;

	if (near->x > far->x)
	{
		temp = near->x;
		near->x = far->x;
		far->x = temp;
	}
	if (near->y > far->y)
	{
		temp = near->y;
		near->y = far->y;
		far->y = temp;
	}
	if (near->z > far->z)
	{
		temp = near->z;
		near->z = far->z;
		far->z = temp;
	}
}

double	intersect_box(t_ray *ray, t_obj *box)
{
	t_vec3f	near;
	t_vec3f	far;
	t_ray	r;

	r = transform_ray(ray, box);
	near.x = (-0.5 - r.origin.x) / r.direction.x;
	far.x = (0.5 - r.origin.x) / r.direction.x;
	near.y = (-0.5 - r.origin.y) / r.direction.y;
	far.y = (0.5 - r.origin.y) / r.direction.y;
	near.z = (-0.5 - r.origin.z) / r.direction.z;
	far.z = (0.5 - r.origin.z) / r.direction.z;
	sort(&near, &far);
	if (near.x > far.y || near.y > far.x)
		return (0);
	if (near.y > near.x)
		near.x = near.y;
	if (far.y < far.x)
		far.x = far.y;
	if (near.x > far.z || near.z > far.x)
		return (0);
	if (near.z > near.x)
		near.x = near.z;
	if (far.z < far.x)
		far.x = far.z;
	return (near.x);
}
