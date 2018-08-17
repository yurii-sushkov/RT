/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:28:09 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 17:00:30 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Чтобы отражение было правильным, вектор ray_direction
**	должен указывать в сторону точки отражения, а не от нее.
**	Для этого есть параметр rev.
**	Если reverse != 0, то функция развернет вектор перед вычислениями.
*/

t_vec3f	get_reflection(t_vec3f ray_direction, t_vec3f normal, int reverse)
{
	double	dot;
	t_vec3f	r;

	if (reverse)
	{
		ray_direction.x = -ray_direction.x;
		ray_direction.y = -ray_direction.y;
		ray_direction.z = -ray_direction.z;
	}
	dot = dot_product(&ray_direction, &normal);
	r.x = 2 * dot * normal.x - ray_direction.x;
	r.y = 2 * dot * normal.y - ray_direction.y;
	r.z = 2 * dot * normal.z - ray_direction.z;
	return (r);
}

void	reflection_skybox(t_cast *c, t_cast *c_new)
{
	skybox(c_new);
	c->col.r += c_new->col.r * c->closest_obj->reflective;
	c->col.g += c_new->col.g * c->closest_obj->reflective;
	c->col.b += c_new->col.b * c->closest_obj->reflective;
}

void	process_reflection(t_cast *c)
{
	t_cast	c_new;

	c_new = *c;
	c_new.depth = c->depth - 1;
	reset_color(&(c_new.col));
	c_new.ray.origin = c->shadow_ray.origin;
	c_new.ray.direction = get_reflection(c->ray.direction, c->n, 1);
	c_new.closest_obj = intersect(c_new.d, &(c_new.ray), &(c_new.t));
	if (c_new.closest_obj)
	{
		shadow_ray(&c_new);
		c->col.r += c_new.col.r * c->closest_obj->reflective;
		c->col.g += c_new.col.g * c->closest_obj->reflective;
		c->col.b += c_new.col.b * c->closest_obj->reflective;
	}
	else
		reflection_skybox(c, &c_new);
}
