/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:27:40 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:27:43 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_forward(int key, t_data *d)
{
	if (key == W)
	{
		d->cam.pos.x += d->cam.direction.x * ((double)d->cam.speed / 100);
		d->cam.pos.y += d->cam.direction.y * ((double)d->cam.speed / 100);
		d->cam.pos.z += d->cam.direction.z * ((double)d->cam.speed / 100);
	}
	else if (key == S)
	{
		d->cam.pos.x -= d->cam.direction.x * ((double)d->cam.speed / 100);
		d->cam.pos.y -= d->cam.direction.y * ((double)d->cam.speed / 100);
		d->cam.pos.z -= d->cam.direction.z * ((double)d->cam.speed / 100);
	}
	draw(d);
}

void	move_sideways(int key, t_data *d)
{
	if (key == A)
	{
		d->cam.pos.x -= d->cam.right.x * ((double)d->cam.speed / 100);
		d->cam.pos.y -= d->cam.right.y * ((double)d->cam.speed / 100);
		d->cam.pos.z -= d->cam.right.z * ((double)d->cam.speed / 100);
	}
	else if (key == D)
	{
		d->cam.pos.x += d->cam.right.x * ((double)d->cam.speed / 100);
		d->cam.pos.y += d->cam.right.y * ((double)d->cam.speed / 100);
		d->cam.pos.z += d->cam.right.z * ((double)d->cam.speed / 100);
	}
	draw(d);
}

void	move_vertically(int key, t_data *d)
{
	if (key == F)
	{
		d->cam.pos.x -= d->cam.up.x * ((double)d->cam.speed / 100);
		d->cam.pos.y -= d->cam.up.y * ((double)d->cam.speed / 100);
		d->cam.pos.z -= d->cam.up.z * ((double)d->cam.speed / 100);
	}
	else if (key == R)
	{
		d->cam.pos.x += d->cam.up.x * ((double)d->cam.speed / 100);
		d->cam.pos.y += d->cam.up.y * ((double)d->cam.speed / 100);
		d->cam.pos.z += d->cam.up.z * ((double)d->cam.speed / 100);
	}
	draw(d);
}

void	rotate_horizontally(int key, t_data *d)
{
	t_vec3f	look_at;

	look_at.x = d->cam.pos.x + d->cam.direction.x;
	look_at.y = d->cam.pos.y + d->cam.direction.y;
	look_at.z = d->cam.pos.z + d->cam.direction.z;
	if (key == LEFT)
	{
		look_at.x -= d->cam.right.x * ((double)d->cam.speed / 300);
		look_at.y -= d->cam.right.y * ((double)d->cam.speed / 100);
		look_at.z -= d->cam.right.z * ((double)d->cam.speed / 100);
	}
	else
	{
		look_at.x += d->cam.right.x * ((double)d->cam.speed / 300);
		look_at.y += d->cam.right.y * ((double)d->cam.speed / 300);
		look_at.z += d->cam.right.z * ((double)d->cam.speed / 300);
	}
	d->cam.direction.x = look_at.x - d->cam.pos.x;
	d->cam.direction.y = look_at.y - d->cam.pos.y;
	d->cam.direction.z = look_at.z - d->cam.pos.z;
	normalize(&(d->cam.direction));
	init_cam(d);
	draw(d);
}

void	rotate_vertically(int key, t_data *d)
{
	t_vec3f	look_at;

	look_at.x = d->cam.pos.x + d->cam.direction.x;
	look_at.y = d->cam.pos.y + d->cam.direction.y;
	look_at.z = d->cam.pos.z + d->cam.direction.z;
	if (key == DOWN)
	{
		look_at.x -= d->cam.up.x * ((double)d->cam.speed / 300);
		look_at.y -= d->cam.up.y * ((double)d->cam.speed / 300);
		look_at.z -= d->cam.up.z * ((double)d->cam.speed / 300);
	}
	else
	{
		look_at.x += d->cam.up.x * ((double)d->cam.speed / 300);
		look_at.y += d->cam.up.y * ((double)d->cam.speed / 300);
		look_at.z += d->cam.up.z * ((double)d->cam.speed / 300);
	}
	d->cam.direction.x = look_at.x - d->cam.pos.x;
	d->cam.direction.y = look_at.y - d->cam.pos.y;
	d->cam.direction.z = look_at.z - d->cam.pos.z;
	normalize(&(d->cam.direction));
	init_cam(d);
	draw(d);
}
