/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:02 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:40:03 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_variables(t_vec3f *amount, double *distance, t_ray *r)
{
	amount->x = 1;
	amount->y = 1;
	amount->z = 1;
	*distance = vec3len(r->direction);
	normalize(&(r->direction));
}

/*
**	Обрабатывает цвет поверхности объекта,
**	прежде чем обрабатывать отражения и прозрачность
*/

void	get_surface_color(t_cast *c)
{
	t_light	*l;
	t_vec3f	light_amount;

	l = c->d->light;
	while (l)
	{
		get_light_direction(l, &(c->shadow_ray.origin),
			&(c->shadow_ray.direction));
		light_amount = get_light_amount(c->d, c->shadow_ray, l);
		if (light_amount.x || light_amount.y || light_amount.z)
		{
			light_amount.x *= (1 - c->d->ambient);
			light_amount.y *= (1 - c->d->ambient);
			light_amount.z *= (1 - c->d->ambient);
			normalize(&(c->shadow_ray.direction));
			process_light(c, light_amount);
			process_shine(c);
		}
		l = l->next;
	}
	c->col.r += c->closest_obj->col.r * c->d->ambient;
	c->col.g += c->closest_obj->col.g * c->d->ambient;
	c->col.b += c->closest_obj->col.b * c->d->ambient;
}

void	next_intersection(t_ray *r, double t)
{
	r->origin.x += r->direction.x * t + r->direction.x * 0.000001;
	r->origin.y += r->direction.y * t + r->direction.y * 0.000001;
	r->origin.z += r->direction.z * t + r->direction.z * 0.000001;
}

void	init_overall_distance(t_light *l, double *od, double *t)
{
	if (l->directional)
		*od = 0;
	else
		*od = *t;
}

/*
**	Принимает t_data и луч от точки пересечения к источнику света.
**	Луч по очереди пересекается со всеми объектами на пути к источнику света.
**	Когда луч дошел до источника света,
**	или когда оставшееся количество света становится равным нулю,
**	функция завершает работу и возвращает количество света,
**	достигающее точки пересечения, в виде вектора,
**	где x == red, y == green, z == blue
*/

t_vec3f	get_light_amount(t_data *d, t_ray r, t_light *l)
{
	t_obj	*closest;
	t_vec3f	amount;
	double	distance_to_light;
	double	overall_distance;
	double	t;

	init_variables(&amount, &distance_to_light, &r);
	closest = intersect(d, &r, &t);
	init_overall_distance(l, &overall_distance, &t);
	while (closest && overall_distance < distance_to_light &&
		distance_to_light - overall_distance > 0.00001)
	{
		amount.x *= closest->transparency * ((double)closest->col.r / 255.0);
		amount.y *= closest->transparency * ((double)closest->col.g / 255.0);
		amount.z *= closest->transparency * ((double)closest->col.b / 255.0);
		if (amount.x == 0 && amount.y == 0 && amount.z == 0)
			return (amount);
		next_intersection(&r, t);
		closest = intersect(d, &r, &t);
		overall_distance += t;
		if (l->directional)
			overall_distance = 0;
	}
	return (amount);
}
