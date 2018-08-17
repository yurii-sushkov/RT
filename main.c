/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:50:32 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 09:48:34 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Срабатывает при нажатии на красный крестик
*/

int		quit(t_data *d)
{
	mlx_destroy_window(d->win.mlx, d->win.win);
	exit(0);
}

/*
**	В чем суть: некоторые вещи(например, сворачивание окна)
**	могут повредить окно, и часть изображения теряется.
**	Точнее, когда-то так было.
**	В нынешней версии Mac OS X этой проблемы нет,
**	но пункт в форме проверки остался.
**	Когда происходит такое событие - вызывается эта функция,
**	и заново пихает уже готовую картинку в окно.
*/

int		manage_expose(t_data *d)
{
	mlx_put_image_to_window(d->win.mlx, d->win.win, d->img.id, 0, 0);
	if (d->menu_visible)
		draw_menu(d);
	return (0);
}

/*
**	Стандартные значения всяких штук
*/

void	prepare(t_data *d)
{
	d->win.mlx = mlx_init();
	d->win.size.x = 800;
	d->win.size.y = 480;
	d->light = 0;
	d->light_count = 0;
	d->cam.pos.x = 0;
	d->cam.pos.y = 0;
	d->cam.pos.z = 0;
	d->cam.up.x = 0;
	d->cam.up.y = 1;
	d->cam.up.z = 0;
	d->cam.direction.x = 0;
	d->cam.direction.y = 0;
	d->cam.direction.z = -1;
	d->obj = 0;
	d->max_depth = 5;
	d->ambient = 0;
	d->menu_visible = 0;
	d->threads = 2;
	d->speed_mode = 0;
	d->cam.speed = 20;
	d->skybox = 1;
}

void	hook_hooks(t_data *d)
{
	mlx_hook(d->win.win, 2, 0, &keyboard_input, d);
	mlx_hook(d->win.win, 17, 17, &quit, d);
	mlx_mouse_hook(d->win.win, &mouse_input, d);
	mlx_expose_hook(d->win.win, &manage_expose, d);
}

int		main(int ac, char **av)
{
	t_data		d;
	int			fd;

	if (ac != 2)
		ft_error("usage: ./RT <file>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error: invalid file");
	prepare(&d);
	read_file(&d, fd);
	if (!d.obj)
		ft_error("Error: file is invalid or has no objects.");
	init_cam(&d);
	d.win.win = mlx_new_window(d.win.mlx,
		d.win.size.x, d.win.size.y,
		"My Little Project: Ray Tracing is Magic");
	new_img(&(d.win), &(d.img));
	hook_hooks(&d);
	draw(&d);
	mlx_loop(d.win.mlx);
	return (0);
}
