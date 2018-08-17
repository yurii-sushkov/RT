/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 09:15:02 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 12:17:03 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cam_move(int key, t_data *d)
{
	if (key == W || key == S)
		move_forward(key, d);
	else if (key == A || key == D)
		move_sideways(key, d);
	else if (key == R || key == F)
		move_vertically(key, d);
	else if (key == LEFT || key == RIGHT)
		rotate_horizontally(key, d);
	else if (key == DOWN || key == UP)
		rotate_vertically(key, d);
}

void	handle_input(int key, t_data *d)
{
	if (key == W || key == A || key == S || key == D || key == R || key == F
			|| key == UP || key == DOWN || key == LEFT || key == RIGHT)
		cam_move(key, d);
	else if (key == SPACE)
		toggle_menu(d);
}

/*
**	Следующие функции существуют только для графического меню,
**	больше ни для чего мышь не используется
**	В зависимости от того, какая кнопка нажата,
**	может потребоваться пересчитать все. А может не потребоваться.
**	Для этого есть переменная recalculate
*/

int		mouse_input_part_3(int x, int y, t_data *d)
{
	if (button_clicked(vec2(x, y), vec2(170, 120),
		vec2(220, 145)) && d->skybox)
	{
		d->skybox = 0;
		return (1);
	}
	return (0);
}

int		mouse_input_part_2(int x, int y, t_data *d)
{
	if (button_clicked(vec2(x, y), vec2(80, 50),
		vec2(170, 75)) && d->speed_mode)
	{
		d->speed_mode = 0;
		return (1);
	}
	else if (button_clicked(vec2(x, y), vec2(170, 50),
		vec2(240, 75)) && !d->speed_mode)
	{
		d->speed_mode = 1;
		return (1);
	}
	else if (button_clicked(vec2(x, y), vec2(110, 120),
		vec2(150, 145)) && !d->skybox)
	{
		d->skybox = 1;
		return (1);
	}
	return (mouse_input_part_3(x, y, d));
}

int		mouse_input(int recalculate, int x, int y, t_data *d)
{
	recalculate = 0;
	if (d->menu_visible)
	{
		if (button_clicked(vec2(x, y),
			vec2(165, 12), vec2(195, 42)) && d->threads < 4)
			d->threads++;
		else if (button_clicked(vec2(x, y),
			vec2(205, 12), vec2(235, 42)) && d->threads > 1)
			d->threads--;
		else if (button_clicked(vec2(x, y),
			vec2(165, 80), vec2(195, 110)) && d->cam.speed < 100)
			d->cam.speed += 5;
		else if (button_clicked(vec2(x, y),
			vec2(205, 80), vec2(235, 110)) && d->cam.speed > 5)
			d->cam.speed -= 5;
		else
			recalculate = mouse_input_part_2(x, y, d);
		if (recalculate)
			draw(d);
		else
			redraw(d);
	}
	return (1);
}
