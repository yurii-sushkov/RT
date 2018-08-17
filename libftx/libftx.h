/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:53:28 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/16 07:15:16 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTX_H
# define LIBFTX_H

# include <mlx.h>

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_vec2f
{
	double		x;
	double		y;
}				t_vec2f;

typedef struct	s_vec3
{
	int			x;
	int			y;
	int			z;
}				t_vec3;

typedef struct	s_vec3f
{
	double		x;
	double		y;
	double		z;
}				t_vec3f;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_vec2		size;
}				t_win;

typedef struct	s_img
{
	void		*id;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_img;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

/*
**	Создает в памяти новое изображение,
**	привязанное к идентификатору mlx из *win.
**	Записывает id и addr изображения в *img.
*/
void			new_img(t_win *win, t_img *img);

/*
**	Запихивает пиксель заданного цвета в изображение.
*/
void			putpixel(t_win *win, t_img *img, t_vec2 pos, t_color c);

t_color			getpixel(t_win *win, t_img *img, int x, int y);

t_vec2			vec2(int x, int y);
double			vec2len(t_vec2 vec);
double			vec2flen(t_vec2f vec);

/*
**	Принимает значения цвета, возвращает t_color.
*/
t_color			tcol(int r, int g, int b, int a);

#endif
