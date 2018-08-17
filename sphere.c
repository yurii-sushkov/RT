/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:47:19 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:02:36 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	dot_product(t_vec3f *v1, t_vec3f *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

void	ft_swap(double *d1, double *d2)
{
	double	temp;

	temp = *d1;
	*d1 = *d2;
	*d2 = temp;
}

int		quadratic_equation(double a, double b, double c, double x[2])
{
	float d;
	float q;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	if (d == 0)
	{
		x[0] = -0.5 * b / a;
		x[1] = x[0];
		return (1);
	}
	if (b < 0)
		q = -0.5 * (b - sqrt(d));
	else
		q = -0.5 * (b + sqrt(d));
	x[0] = q / a;
	x[1] = c / q;
	if (x[0] > x[1])
		ft_swap(&(x[0]), &(x[1]));
	if (x[0] == 0)
		x[0] = 0.000001;
	return (2);
}

double	closest(double t[2])
{
	if (t[0] < 0 && t[1] < 0)
		return (0);
	else if (t[0] > 0 && t[1] < 0)
		return (t[0]);
	else if (t[0] < 0 && t[1] >= 0)
		return (t[1]);
	else if (t[0] >= 0 && t[1] >= 0
			&& t[1] < t[0])
		return (t[1]);
	if (t[0] == 0)
		t[0] = 0.000001;
	return (t[0]);
}

double	intersect_sphere(t_ray *ray, t_obj *s)
{
	t_ray	r;
	double	a;
	double	b;
	double	c;
	double	t[2];

	r = transform_ray(ray, s);
	a = dot_product(&(r.direction), &(r.direction));
	b = 2 * dot_product(&(r.direction), &(r.origin));
	c = dot_product(&(r.origin), &(r.origin)) - 1;
	if (!quadratic_equation(a, b, c, t))
		return (0);
	return (closest(t));
}
