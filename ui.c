/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:41:33 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:41:35 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	put_text(t_data *d, t_vec2 pos, int color, char *text)
{
	mlx_string_put(d->win.mlx, d->win.win, pos.x + 1, pos.y + 1,
		rgb_to_int(80, 80, 80), text);
	mlx_string_put(d->win.mlx, d->win.win, pos.x, pos.y, color, text);
}

void	draw_rect(t_data *d, t_vec2 topleft, t_vec2 botright, t_color color)
{
	t_win	win;
	t_img	img;
	t_vec2	pos;

	win.size.x = botright.x - topleft.x;
	win.size.y = botright.y - topleft.y;
	img.id = mlx_new_image(d->win.mlx, win.size.x, win.size.y);
	img.addr = mlx_get_data_addr(img.id, &(img.bpp), &(img.len), &(img.endian));
	pos.x = 0;
	while (pos.x <= win.size.x)
	{
		pos.y = 0;
		while (pos.y <= win.size.y)
		{
			putpixel(&win, &img, pos, color);
			pos.y++;
		}
		pos.x++;
	}
	mlx_put_image_to_window(d->win.mlx, d->win.win, img.id,
		topleft.x, topleft.y);
	mlx_destroy_image(d->win.mlx, img.id);
}

void	plus_button(t_data *d, t_vec2 pos)
{
	draw_rect(d, pos, vec2(pos.x + 30, pos.y + 30),
		tcol(170, 200, 100, 100));
	draw_rect(d, vec2(pos.x + 5, pos.y + 12),
		vec2(pos.x + 25, pos.y + 18), tcol(90, 120, 20, 0));
	draw_rect(d, vec2(pos.x + 12, pos.y + 5),
		vec2(pos.x + 18, pos.y + 25), tcol(90, 120, 20, 0));
}

void	minus_button(t_data *d, t_vec2 pos)
{
	draw_rect(d, pos, vec2(pos.x + 30, pos.y + 30),
		tcol(170, 200, 100, 100));
	draw_rect(d, vec2(pos.x + 5, pos.y + 12),
		vec2(pos.x + 25, pos.y + 18), tcol(99, 17, 69, 0));
}

int		keyboard_input(int key, t_data *d)
{
	if (key == 53)
	{
		mlx_destroy_window(d->win.mlx, d->win.win);
		exit(0);
	}
	else
		handle_input(key, d);
	return (0);
}
