/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:02:21 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 08:57:13 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	place_object(t_obj *obj, double x, double y, double z)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->pos.z = z;
}

void	paint_object(t_obj *obj, int r, int g, int b)
{
	obj->col.r = r;
	obj->col.g = g;
	obj->col.b = b;
	obj->col.a = 0;
}

void	rotate_object(t_obj *obj, double x, double y, double z)
{
	obj->direction.x = x;
	obj->direction.y = y;
	obj->direction.z = z;
}

int		new_object(t_data *d, int type)
{
	t_obj	*temp;

	if (type < 1 || type > 6)
		ft_error("Much error, very exit. Wow.");
	temp = d->obj;
	if (!(d->obj = (t_obj *)malloc(sizeof(t_obj))))
		ft_error("Error: malloc has failed.");
	d->obj->type = type;
	d->obj->next = temp;
	place_object(d->obj, 0, 0, 0);
	rotate_object(d->obj, 0, 0, 0);
	if (d->obj->type == 2 || d->obj->type == 5)
		d->obj->direction.y = 1;
	paint_object(d->obj, 255, 255, 255);
	d->obj->reflective = 0;
	d->obj->transparency = 0;
	d->obj->shine = 0;
	d->obj->length = 0;
	d->obj->scale.x = 1;
	d->obj->scale.y = 1;
	d->obj->scale.z = 1;
	d->obj->lamp = 0;
	d->obj->metallic = 0;
	return (1);
}
