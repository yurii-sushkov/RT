/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:59 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 14:26:01 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_shine(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	assign_double(&(d->obj->shine), arr[1]);
	if (d->obj->shine < 0 || d->obj->shine > 1)
		ft_error("Error: object shine should have a value between 0 and 1");
}

void	set_transparency(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	assign_double(&(d->obj->transparency), arr[1]);
	if (d->obj->transparency < 0 || d->obj->transparency > 1)
		ft_error("Error: transparency must be between 0 and 1");
}

void	set_position(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	if (d->obj->lamp)
		ft_error("Error: can't change lamp position");
	assign_double(&(d->obj->pos.x), arr[1]);
	assign_double(&(d->obj->pos.y), arr[2]);
	assign_double(&(d->obj->pos.z), arr[3]);
}

void	set_rotation(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	if (d->obj->type == BOX)
		ft_error("Error: can't rotate boxes");
	if (d->obj->type == 2 || d->obj->type == 5)
	{
		assign_double(&(d->obj->direction.x), arr[1]);
		assign_double(&(d->obj->direction.y), arr[2]);
		assign_double(&(d->obj->direction.z), arr[3]);
		if (d->obj->direction.x == 0
				&& d->obj->direction.y == 0
				&& d->obj->direction.z == 0)
			d->obj->direction.y = 1;
		normalize(&(d->obj->direction));
	}
	else
	{
		assign_deg(&(d->obj->direction.x), arr[1]);
		assign_deg(&(d->obj->direction.y), arr[2]);
		assign_deg(&(d->obj->direction.z), arr[3]);
	}
}

void	add_lamp(t_data *d, char **arr)
{
	t_light	*new;

	if (d->light_count >= 15)
		ft_error("Error: up to 15 light sources are supported.");
	if (!(new = (t_light *)malloc(sizeof(t_light))))
		ft_error("Error: malloc failed when adding lights.");
	new->directional = 0;
	assign_double(&(new->pos.x), arr[1]);
	assign_double(&(new->pos.y), arr[2]);
	assign_double(&(new->pos.z), arr[3]);
	new->next = d->light;
	d->light = new;
	d->light_count += 1;
	new_object(d, SPHERE);
	assign_double(&(d->obj->pos.x), arr[1]);
	assign_double(&(d->obj->pos.y), arr[2]);
	assign_double(&(d->obj->pos.z), arr[3]);
	d->obj->lamp = 1;
	d->obj->transparency = 1;
	d->obj->scale.x = 0.01;
	d->obj->scale.y = 0.01;
	d->obj->scale.z = 0.01;
}
