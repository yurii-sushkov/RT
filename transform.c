/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:04:27 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:02:45 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Принимает точку и указатель на объект;
**	возвращает координаты, которые имела бы та самая точка,
**	если бы объект стоял вертикально вдоль оси Y, имел размер 1,
**	и находился на (0, 0, 0)
*/

t_vec3f	to_object_space(t_vec3f vec, t_obj *obj)
{
	vec.x -= obj->pos.x;
	vec.y -= obj->pos.y;
	vec.z -= obj->pos.z;
	vec.x /= obj->scale.x;
	vec.y /= obj->scale.y;
	vec.z /= obj->scale.z;
	rotate_vec(&vec, &(obj->direction));
	return (vec);
}

/*
**	То же самое, но наоборот
*/

t_vec3f	to_world_space(t_vec3f vec, t_obj *obj)
{
	reverse_rotation(&vec, &(obj->direction));
	vec.x *= obj->scale.x;
	vec.y *= obj->scale.y;
	vec.z *= obj->scale.z;
	vec.x = vec.x + obj->pos.x;
	vec.y = vec.y + obj->pos.y;
	vec.z = vec.z + obj->pos.z;
	return (vec);
}

/*
**	Поворачивает вектор, как можно догадаться из названия
*/

void	rotate_vec(t_vec3f *vec, t_vec3f *rot)
{
	double	temp;
	double	vcos;
	double	vsin;

	vcos = cos(rot->z);
	vsin = sin(rot->z);
	temp = vec->x;
	vec->x = temp * vcos - vec->y * vsin;
	vec->y = temp * vsin + vec->y * vcos;
	vcos = cos(rot->x);
	vsin = sin(rot->x);
	temp = vec->y;
	vec->y = temp * vcos - vec->z * vsin;
	vec->z = temp * vsin + vec->z * vcos;
	vcos = cos(rot->y);
	vsin = sin(rot->y);
	temp = vec->x;
	vec->x = temp * vcos - vec->z * vsin;
	vec->z = temp * vsin + vec->z * vcos;
}

/*
**	Принимает значения поворота, на которые ранее был повернут вектор,
**	и возвращает его в исходное состояние.
*/

void	reverse_rotation(t_vec3f *vec, t_vec3f *rot)
{
	double	temp;
	double	vcos;
	double	vsin;

	vcos = cos(-rot->y);
	vsin = sin(-rot->y);
	temp = vec->x;
	vec->x = temp * vcos - vec->z * vsin;
	vec->z = temp * vsin + vec->z * vcos;
	vcos = cos(-rot->x);
	vsin = sin(-rot->x);
	temp = vec->y;
	vec->y = temp * vcos - vec->z * vsin;
	vec->z = temp * vsin + vec->z * vcos;
	vcos = cos(-rot->z);
	vsin = sin(-rot->z);
	temp = vec->x;
	vec->x = temp * vcos - vec->y * vsin;
	vec->y = temp * vsin + vec->y * vcos;
}

/*
**	С объектами гораздо проще работать, когда они находятся вдоль какой-то оси
**	и имеют размер 1.
**	Соответственно, вместо того, чтобы трансформировать сам объект,
**	проще трансформировать луч.
**	Эта функция принимает "настоящий" луч, и делает из него такой,
**	который пересекается с не-трансформированным объекто
**	на таком же расстоянии,
**	на каком оригинальный луч пересекается с трансформированным.
*/

t_ray	transform_ray(t_ray *src, t_obj *obj)
{
	t_ray	dest;

	dest.origin.x = src->origin.x - obj->pos.x;
	dest.origin.y = src->origin.y - obj->pos.y;
	dest.origin.z = src->origin.z - obj->pos.z;
	dest.origin.x /= obj->scale.x;
	dest.origin.y /= obj->scale.y;
	dest.origin.z /= obj->scale.z;
	dest.direction.x = src->direction.x / obj->scale.x;
	dest.direction.y = src->direction.y / obj->scale.y;
	dest.direction.z = src->direction.z / obj->scale.z;
	rotate_vec(&(dest.origin), &(obj->direction));
	rotate_vec(&(dest.direction), &(obj->direction));
	return (dest);
}
