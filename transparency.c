/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:41:29 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:41:30 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	calculate_transmitted_light(t_cast *c, t_vec3f *transmitted)
{
	transmitted->x = ((double)c->closest_obj->col.r / 255)
		* c->closest_obj->transparency;
	transmitted->y = ((double)c->closest_obj->col.g / 255)
		* c->closest_obj->transparency;
	transmitted->z = ((double)c->closest_obj->col.b / 255)
		* c->closest_obj->transparency;
}

void	exit_current_object(t_cast *c, t_cast *temp)
{
	int	i;

	i = 0;
	temp->closest_obj = intersect(c->d, &(temp->ray), &(temp->t));
	while (temp->closest_obj == c->closest_obj && i < 10)
	{
		temp->ray.origin.x += temp->ray.direction.x
			* temp->t + temp->ray.direction.x * 0.000001;
		temp->ray.origin.y += temp->ray.direction.y
			* temp->t + temp->ray.direction.y * 0.000001;
		temp->ray.origin.z += temp->ray.direction.z
			* temp->t + temp->ray.direction.z * 0.000001;
		temp->closest_obj = intersect(c->d, &(temp->ray), &(temp->t));
		i++;
	}
}

void	transparency_skybox(t_cast *c, t_cast *temp, t_vec3f *transmitted)
{
	skybox(temp);
	c->col.r += (double)temp->col.r
		* transmitted->x * c->closest_obj->transparency;
	c->col.g += (double)temp->col.g
		* transmitted->y * c->closest_obj->transparency;
	c->col.b += (double)temp->col.b
		* transmitted->z * c->closest_obj->transparency;
}

void	process_transparency(t_cast *c)
{
	t_cast	temp;
	t_vec3f transmitted;

	calculate_transmitted_light(c, &transmitted);
	temp = *c;
	c->col.r -= c->col.r * c->closest_obj->transparency;
	c->col.g -= c->col.g * c->closest_obj->transparency;
	c->col.b -= c->col.b * c->closest_obj->transparency;
	temp.ray = c->ray;
	exit_current_object(c, &temp);
	if (temp.closest_obj)
	{
		reset_color(&(temp.col));
		shadow_ray(&temp);
		c->col.r += (double)temp.col.r
			* transmitted.x * c->closest_obj->transparency;
		c->col.g += (double)temp.col.g
			* transmitted.y * c->closest_obj->transparency;
		c->col.b += (double)temp.col.b
			* transmitted.z * c->closest_obj->transparency;
	}
	else
		transparency_skybox(c, &temp, &transmitted);
}
