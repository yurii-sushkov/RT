/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:55 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:40:56 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_light(t_data *d, char **arr, int directional)
{
	t_light	*new;

	if (d->light_count >= 15)
		ft_error("Error: up to 15 light sources are supported.");
	if (!(new = (t_light *)malloc(sizeof(t_light))))
		ft_error("Error: malloc failed when adding lights.");
	new->directional = directional;
	assign_double(&(new->pos.x), arr[1]);
	assign_double(&(new->pos.y), arr[2]);
	assign_double(&(new->pos.z), arr[3]);
	if (directional)
		normalize(&(new->pos));
	new->next = d->light;
	d->light = new;
	d->light_count += 1;
}

void	set_camera(t_data *d, char **arr)
{
	assign_double(&(d->cam.pos.x), arr[1]);
	assign_double(&(d->cam.pos.y), arr[2]);
	assign_double(&(d->cam.pos.z), arr[3]);
	if (!arr[4])
		ft_error("Error: camera direction not set.");
	if (!arr[5])
		ft_error("Error: camera direction not set.");
	if (!arr[6])
		ft_error("Error: camera direction not set.");
	d->cam.direction.x = ft_atod(arr[4]) - d->cam.pos.x;
	d->cam.direction.y = ft_atod(arr[5]) - d->cam.pos.y;
	d->cam.direction.z = ft_atod(arr[6]) - d->cam.pos.z;
	normalize(&(d->cam.direction));
	if (!d->cam.direction.x &&
		!d->cam.direction.y &&
		!d->cam.direction.z)
		d->cam.direction.z = -1;
}

void	set_ambient(t_data *d, char **arr)
{
	assign_double(&(d->ambient), arr[1]);
	if (d->ambient < 0 || d->ambient > 1)
		ft_error("Error: ambient lighting should have a value between 0 and 1");
}

void	set_reflective(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	assign_double(&(d->obj->reflective), arr[1]);
	if (d->obj->reflective < 0 || d->obj->reflective > 1)
		ft_error("Error: reflectiveness must be between 0 and 1");
}

void	set_depth(t_data *d, char **arr)
{
	assign_int(&(d->max_depth), arr[1]);
	if (d->max_depth < 0)
		ft_error("Error: reflection depth can't be negative");
}
