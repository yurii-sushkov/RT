/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:02:15 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 14:59:57 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	intersect_cone(t_ray *ray, t_obj *cone)
{
	double	a;
	double	b;
	double	c;
	double	t[2];
	t_ray	r;

	r = transform_ray(ray, cone);
	a = r.direction.x * r.direction.x
		+ r.direction.z * r.direction.z
		- r.direction.y * r.direction.y;
	b = 2 * r.origin.x * r.direction.x
		+ 2 * r.origin.z * r.direction.z
		- 2 * r.origin.y * r.direction.y;
	c = r.origin.x * r.origin.x
		+ r.origin.z * r.origin.z
		- r.origin.y * r.origin.y;
	a = (double)quadratic_equation(a, b, c, t);
	if (a == 0)
		return (0);
	else if (a == 1)
		return (t[0]);
	return (closest(t));
}
