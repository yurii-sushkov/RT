/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:23:18 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:02:26 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	ft_pow(double nbr, int power)
{
	double	result;

	result = nbr;
	while (power-- > 1)
		result *= nbr;
	return (result);
}

void	get_light_direction(t_light *l, t_vec3f *p, t_vec3f *dest)
{
	if (l->directional)
	{
		dest->x = l->pos.x;
		dest->y = l->pos.y;
		dest->z = l->pos.z;
	}
	else
	{
		dest->x = l->pos.x - p->x;
		dest->y = l->pos.y - p->y;
		dest->z = l->pos.z - p->z;
	}
}

void	get_intersection_point(t_ray *ray, double t, t_vec3f *dest)
{
	dest->x = ray->origin.x + t * ray->direction.x;
	dest->y = ray->origin.y + t * ray->direction.y;
	dest->z = ray->origin.z + t * ray->direction.z;
}

void	skybox(t_cast *c)
{
	t_vec3f	up;
	double	cos;

	if (c->d->skybox)
	{
		up.x = 0;
		up.y = 1;
		up.z = 0;
		cos = dot_product(&(c->ray.direction), &up);
		cos += 1;
		c->col.r = 100 * cos;
		c->col.g = 120 * cos;
		c->col.b = 10 + 150 * cos;
		cap_color(&(c->col));
	}
	else
		reset_color(&(c->col));
}
