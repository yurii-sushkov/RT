/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:02:36 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:11:18 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3f	sphere_normal(t_obj *obj, t_vec3f *p)
{
	t_vec3f	normal;

	normal.x = p->x - obj->pos.x;
	normal.y = p->y - obj->pos.y;
	normal.z = p->z - obj->pos.z;
	normalize(&normal);
	return (normal);
}

/*
**	Функция cylinder_normal НЕ нормализует вектор.
**	Вместо этого он нормализуется в функции get_normal.
**	Всё потому, что в функции уже есть 25 строк.
**	Спасибо Norminette, что приходится так извращаться.
*/

t_vec3f	cylinder_normal(t_obj *obj, t_vec3f *p)
{
	t_vec3f	hit;
	t_vec3f	center;
	t_vec3f	temp;

	hit = to_object_space(*p, obj);
	center.x = 0;
	center.y = hit.y;
	center.z = 0;
	if (obj->length > 0)
	{
		temp.x = hit.x;
		temp.z = hit.z;
		temp.y = 0;
		if (vec3len(temp) < 0.99999)
		{
			reverse_rotation(&center, &(obj->direction));
			normalize(&center);
			return (center);
		}
	}
	center = to_world_space(center, obj);
	hit.x = p->x - center.x;
	hit.y = p->y - center.y;
	hit.z = p->z - center.z;
	return (hit);
}

t_vec3f	cone_normal(t_obj *obj, t_vec3f *p)
{
	t_vec3f	hit;
	t_vec3f	center;
	double	height;
	double	hypothenuse;
	double	offset;

	hit = to_object_space(*p, obj);
	hypothenuse = vec3len(hit);
	height = hit.y;
	offset = sqrt(hypothenuse * hypothenuse - height * height);
	center.x = 0;
	center.z = 0;
	if (height < 0)
		offset = -offset;
	center.y = hit.y + offset;
	center = to_world_space(center, obj);
	hit.x = p->x - center.x;
	hit.y = p->y - center.y;
	hit.z = p->z - center.z;
	normalize(&hit);
	return (hit);
}

t_vec3f	box_normal(t_obj *obj, t_vec3f *p)
{
	t_vec3f	hit;
	t_vec3f	n;

	hit = to_object_space(*p, obj);
	n.x = 0;
	n.y = 0;
	n.z = 0;
	if (fabs(hit.x - 0.5) < 0.000001)
		n.x = 1;
	else if (fabs(hit.x + 0.5) < 0.000001)
		n.x = -1;
	else if (fabs(hit.y - 0.5) < 0.000001)
		n.y = 1;
	else if (fabs(hit.y + 0.5) < 0.000001)
		n.y = -1;
	else if (fabs(hit.z - 0.5) < 0.000001)
		n.z = 1;
	else if (fabs(hit.z + 0.5) < 0.000001)
		n.z = -1;
	reverse_rotation(&n, &(obj->direction));
	normalize(&n);
	return (n);
}

t_vec3f	get_normal(t_obj *obj, t_vec3f *p)
{
	t_vec3f	normal;

	if (obj->type == 1)
		return (sphere_normal(obj, p));
	else if (obj->type == 2 || obj->type == 5)
		return (obj->direction);
	else if (obj->type == 3)
	{
		normal = cylinder_normal(obj, p);
		normalize(&normal);
		return (normal);
	}
	else if (obj->type == 4)
		return (cone_normal(obj, p));
	else
		return (box_normal(obj, p));
}
