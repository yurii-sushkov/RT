/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:06:17 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 16:43:02 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	process_shine(t_cast *c)
{
	double	specular;
	t_vec3f	r;

	r = get_reflection(c->shadow_ray.direction, c->n, 1);
	specular = dot_product(&(c->ray.direction), &r);
	if (specular <= 0)
		specular = 0.0000001;
	specular = ft_pow(specular, 20) * 85 * c->closest_obj->shine;
	if (c->closest_obj->metallic)
	{
		c->col.r += specular * (double)c->closest_obj->col.r / 255;
		c->col.g += specular * (double)c->closest_obj->col.g / 255;
		c->col.b += specular * (double)c->closest_obj->col.b / 255;
	}
	else
	{
		c->col.r += specular;
		c->col.g += specular;
		c->col.b += specular;
	}
}

void	process_light(t_cast *c, t_vec3f amount)
{
	double	brightness;

	brightness = dot_product(&(c->n), &(c->shadow_ray.direction));
	if (brightness < 0)
		brightness = 0;
	c->col.r += c->closest_obj->col.r * brightness * amount.x;
	c->col.g += c->closest_obj->col.g * brightness * amount.y;
	c->col.b += c->closest_obj->col.b * brightness * amount.z;
}

void	add_ambient(t_cast *c)
{
	c->col.r += (int)(c->closest_obj->col.r * c->d->ambient / 2);
	c->col.g += (int)(c->closest_obj->col.g * c->d->ambient / 2);
	c->col.b += (int)(c->closest_obj->col.b * c->d->ambient / 2);
}

void	shadow_ray(t_cast *c)
{
	if (c->closest_obj)
		cast_shadow_ray(c);
	else
		skybox(c);
}

void	cast_shadow_ray(t_cast *c)
{
	double	max_color;

	max_color = 0.95 - (c->closest_obj->shine / 3);
	get_intersection_point(&(c->ray), c->t, &(c->shadow_ray.origin));
	c->n = get_normal(c->closest_obj, &(c->shadow_ray.origin));
	check_normal_direction(&(c->n), &(c->ray));
	c->shadow_ray.origin.x -= c->ray.direction.x * 0.000001 * c->t;
	c->shadow_ray.origin.y -= c->ray.direction.y * 0.000001 * c->t;
	c->shadow_ray.origin.z -= c->ray.direction.z * 0.000001 * c->t;
	get_surface_color(c);
	if (c->closest_obj->reflective && c->depth > 0)
	{
		c->reflectiveness = max_color * c->closest_obj->reflective;
		mul_color(&(c->col),
			(max_color - c->reflectiveness) / c->d->light_count);
		process_reflection(c);
	}
	else
		mul_color(&(c->col), max_color / c->d->light_count);
	if (c->closest_obj->transparency > 0)
		process_transparency(c);
	cap_color(&(c->col));
}
