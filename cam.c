/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:18:05 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 14:59:18 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3f	cross_product(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f	vec;

	vec.x = v1->y * v2->z - v1->z * v2->y;
	vec.y = v1->z * v2->x - v1->x * v2->z;
	vec.z = v1->x * v2->y - v1->y * v2->x;
	return (vec);
}

/*
**	Зная лишь направление камеры,
**	вычисляет векторы "вправо от камеры" и "вверх от камеры"
*/

void	init_cam(t_data *d)
{
	if (d->cam.direction.x == 0 && d->cam.direction.z == 0
		&& (d->cam.direction.y == 1 || d->cam.direction.y == -1))
	{
		d->cam.up.x = 0;
		d->cam.up.y = 0;
		d->cam.up.z = 1;
	}
	else
	{
		d->cam.up.x = 0;
		d->cam.up.y = 1;
		d->cam.up.z = 0;
	}
	d->cam.right = cross_product(&(d->cam.direction), &(d->cam.up));
	d->cam.up = cross_product(&(d->cam.right), &(d->cam.direction));
	normalize(&(d->cam.direction));
	normalize(&(d->cam.up));
	normalize(&(d->cam.right));
}
