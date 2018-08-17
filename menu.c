/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:11 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:40:11 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	menu_threads(t_data *d)
{
	char	*str;

	put_text(d, vec2(15, 15), rgb_to_int(212, 210, 106), "Threads:");
	str = ft_itoa(d->threads);
	put_text(d, vec2(100, 15), rgb_to_int(255, 253, 170), str);
	free(str);
	plus_button(d, vec2(165, 12));
	minus_button(d, vec2(205, 12));
}

void	menu_mode_switch(t_data *d)
{
	put_text(d, vec2(15, 50), rgb_to_int(212, 210, 106), "Mode:");
	if (!d->speed_mode)
	{
		draw_rect(d, vec2(80, 50), vec2(170, 75), tcol(149, 117, 171, 100));
		put_text(d, vec2(90, 50), rgb_to_int(255, 253, 170), "Quality");
		put_text(d, vec2(180, 50), rgb_to_int(212, 210, 106), "Speed");
	}
	else
	{
		draw_rect(d, vec2(170, 50), vec2(240, 75), tcol(149, 117, 171, 100));
		put_text(d, vec2(90, 50), rgb_to_int(212, 210, 106), "Quality");
		put_text(d, vec2(180, 50), rgb_to_int(255, 253, 170), "Speed");
	}
}

void	menu_cam_speed(t_data *d)
{
	char	*str_itoa;
	char	*str;

	put_text(d, vec2(15, 85), rgb_to_int(212, 210, 106), "Cam speed:");
	str_itoa = ft_itoa(d->cam.speed);
	str = ft_strjoin(str_itoa, "%");
	free(str_itoa);
	put_text(d, vec2(120, 85), rgb_to_int(255, 253, 170), str);
	free(str);
	plus_button(d, vec2(165, 80));
	minus_button(d, vec2(205, 80));
}

void	draw_menu(t_data *d)
{
	draw_rect(d, vec2(5, 5), vec2(250, 170), tcol(170, 200, 100, 100));
	menu_threads(d);
	menu_mode_switch(d);
	menu_cam_speed(d);
	menu_skybox(d);
}

void	toggle_menu(t_data *d)
{
	if (d->menu_visible)
	{
		d->menu_visible = 0;
		mlx_put_image_to_window(d->win.mlx, d->win.win, d->img.id, 0, 0);
	}
	else
	{
		d->menu_visible = 1;
		draw_menu(d);
	}
}
