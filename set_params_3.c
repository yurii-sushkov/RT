/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:41:05 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:41:06 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_color(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	assign_int(&(d->obj->col.r), arr[1]);
	assign_int(&(d->obj->col.g), arr[2]);
	assign_int(&(d->obj->col.b), arr[3]);
	if (d->obj->col.r < 0 || d->obj->col.r > 255
		|| d->obj->col.g < 0 || d->obj->col.g > 255
		|| d->obj->col.b < 0 || d->obj->col.b > 255)
		ft_error("Error: colors must be in range between 0 and 255");
}

void	set_length(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	if (d->obj->type != CYLINDER)
		ft_error("Error: bounding length can only be applied to cylinders");
	assign_double(&(d->obj->length), arr[1]);
}

void	set_radius(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	if (d->obj->type != SPHERE && d->obj->type != DISK &&
		d->obj->type != CYLINDER)
		ft_error("Error: radius only works on spheres, disks and cylinders");
	assign_double(&(d->obj->scale.x), arr[1]);
	assign_double(&(d->obj->scale.y), arr[1]);
	assign_double(&(d->obj->scale.z), arr[1]);
	if (d->obj->scale.x <= 0 || d->obj->scale.y <= 0 || d->obj->scale.z <= 0)
		ft_error("Error: object scale must be positive");
}

void	set_scale(t_data *d, char **arr)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	if (d->obj->type != BOX)
		ft_error("Error: scale can only be applied to boxes");
	assign_double(&(d->obj->scale.x), arr[1]);
	assign_double(&(d->obj->scale.y), arr[2]);
	assign_double(&(d->obj->scale.z), arr[3]);
	if (d->obj->scale.x <= 0 || d->obj->scale.y <= 0 || d->obj->scale.z <= 0)
		ft_error("Error: object scale must be positive");
}

void	set_metallic(t_data *d)
{
	if (!(d->obj))
		ft_error("Error: can't set properties when there are no objects");
	d->obj->metallic = 1;
}
