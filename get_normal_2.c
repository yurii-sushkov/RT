/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:39:31 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:39:32 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_normal_direction(t_vec3f *n, t_ray *ray)
{
	double	dot;

	dot = dot_product(n, &(ray->direction));
	if (dot > 0)
	{
		n->x = -n->x;
		n->y = -n->y;
		n->z = -n->z;
	}
}
