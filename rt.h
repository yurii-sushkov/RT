/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:11:28 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/18 16:40:38 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define DEG 0.0174533

# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libftx.h"

# include <pthread.h>

/*
**	Коды клавиш
*/

# define W 13
# define A 0
# define S 1
# define D 2
# define R 15
# define F 3
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define SPACE 49

/*
**	Типы объектов
*/

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4
# define DISK 5
# define BOX 6

typedef struct		s_light
{
	t_vec3f			pos;
	struct s_light	*next;
	int				directional;
}					t_light;

typedef struct		s_obj
{
	int				type;
	int				lamp;
	t_vec3f			pos;
	t_vec3f			direction;
	double			length;
	t_vec3f			scale;
	t_color			col;
	struct s_obj	*next;
	double			transparency;
	double			reflective;
	double			shine;
	int				metallic;
}					t_obj;

typedef struct		s_ray
{
	t_vec3f			origin;
	t_vec3f			direction;
}					t_ray;

typedef struct		s_cam
{
	t_vec3f			pos;
	t_vec3f			direction;
	t_vec3f			right;
	t_vec3f			up;
	int				speed;
}					t_cam;

typedef struct		s_data
{
	t_win			win;
	t_img			img;
	t_obj			*obj;
	t_light			*light;
	int				light_count;
	t_cam			cam;
	int				max_depth;
	double			ambient;
	int				menu_visible;
	int				threads;
	int				speed_mode;
	int				skybox;
}					t_data;

typedef struct		s_cast
{
	t_ray			ray;
	double			t;
	t_color			col;
	t_obj			*closest_obj;
	t_data			*d;
	t_vec3f			n;
	t_ray			shadow_ray;
	int				depth;
	double			reflectiveness;
}					t_cast;

typedef struct		s_thread
{
	t_data			*data;
	int				id;
	int				x;
	int				y;
}					t_thread;

/*
**	Создание объектов
*/

int					new_object(t_data *d, int type);
void				place_object(t_obj *obj, double x, double y, double z);
void				resize_object(t_obj *obj, double size);
void				paint_object(t_obj *obj, int r, int g, int b);
void				rotate_object(t_obj *obj, double x, double y, double z);

/*
**	Собственно, трассировка лучей
*/

int					cast_primary_ray(t_data *d, int x, int y);
int					iterate_pixels(t_data *d);
t_vec3f				pixel_to_point(t_data *d, int x, int y);
void				shadow_ray(t_cast *c);
t_vec3f				get_reflection(t_vec3f ray_direction,
	t_vec3f normal, int reverse);
t_vec3f				get_light_amount(t_data *d, t_ray r, t_light *l);
void				process_light(t_cast *c, t_vec3f amount);
void				process_shine(t_cast *c);
void				get_surface_color(t_cast *c);
void				process_transparency(t_cast *c);
void				get_light_direction(t_light *l, t_vec3f *p, t_vec3f *dest);
void				cast_shadow_ray(t_cast *c);
void				skybox(t_cast *c);

/*
**	Нахождения пересечения с объектом
*/

t_obj				*intersect(t_data *d, t_ray *ray, double *t);
double				intersect_sphere(t_ray *ray, t_obj *s);
double				intersect_plane(t_ray *ray, t_obj *plane);
double				intersect_cylinder(t_ray *ray, t_obj *c);
double				intersect_finite_cylinder(t_ray *ray, t_obj *c);
double				intersect_cone(t_ray *ray, t_obj *cone);
double				intersect_box(t_ray *ray, t_obj *box);

double				intersect_disk(t_ray *ray, t_obj *disk);
double				closest(double t[2]);
void				get_direction(t_vec3f *v1, t_vec3f *v2, t_vec3f *dest);
void				get_intersection_point(t_ray *ray, double t, t_vec3f *dest);
void				make_disk(t_ray *r, t_obj *disk, t_obj *obj);

/*
**	Лень распределять по категориям
*/

double				vec3len(t_vec3f v);
double				dot_product(t_vec3f *v1, t_vec3f *v2);
void				normalize(t_vec3f *v);
int					quadratic_equation(double a, double b,
		double c, double x[2]);
t_vec3f				get_normal(t_obj *obj, t_vec3f *p);
t_ray				transform_ray(t_ray *src, t_obj *obj);
void				rotate_vec(t_vec3f *vec, t_vec3f *rot);
void				reverse_rotation(t_vec3f *vec, t_vec3f *rot);
void				ft_error(char *msg);
void				reset_color(t_color *color);
void				cap_color(t_color *color);
t_vec3f				cylinder_normal(t_obj *obj, t_vec3f	*p);
void				check_normal_direction(t_vec3f *n, t_ray *ray);
double				ft_pow(double nbr, int power);
void				mul_color(t_color *col, double k);
int					rgb_to_int(int r, int g, int b);
void				process_reflection(t_cast *c);
void				draw(t_data *d);
void				redraw(t_data *d);

/*
**	Обработчик файлов сцен
*/

int					read_file(t_data *d, int fd);
void				parse_line_2(t_data *d, char **arr);
void				assign_int(int *dest, char *str);
void				assign_double(double *dest, char *str);
void				assign_deg(double *dest, char *str);
void				init_cam(t_data *d);
double				ft_atod(const char *str);
void				add_light(t_data *d, char **arr, int directional);
void				add_lamp(t_data *d, char **arr);
void				set_position(t_data *d, char **arr);
void				set_rotation(t_data *d, char **arr);
void				set_scale(t_data *d, char **arr);
void				set_color(t_data *d, char **arr);
void				set_reflective(t_data *d, char **arr);
void				set_depth(t_data *d, char **arr);
void				set_length(t_data *d, char **arr);
void				set_camera(t_data *d, char **arr);
void				set_ambient(t_data *d, char **arr);
void				set_shine(t_data *d, char **arr);
void				set_transparency(t_data *d, char **arr);
void				set_radius(t_data *d, char **arr);
void				set_metallic(t_data *d);

/*
**	Трансформации
*/

t_vec3f				to_object_space(t_vec3f	vec, t_obj *obj);
t_vec3f				to_world_space(t_vec3f vec, t_obj *obj);

/*
**	Обработка ввода
*/

int					keyboard_input(int key, t_data *d);
int					mouse_input(int button, int x, int y, t_data *d);
void				handle_input(int key, t_data *d);
int					quit(t_data *d);

/*
**	Камера
*/

void				move_forward(int key, t_data *d);
void				move_sideways(int key, t_data *d);
void				move_vertically(int key, t_data *d);
void				rotate_horizontally(int key, t_data *d);
void				rotate_vertically(int key, t_data *d);

/*
**	Интерфейс
*/

void				toggle_menu(t_data *d);
void				draw_menu(t_data *d);
void				put_text(t_data *d, t_vec2 pos,
	int color, char *text);
void				draw_rect(t_data *d, t_vec2 topleft,
	t_vec2 botright, t_color color);
void				plus_button(t_data *d, t_vec2 pos);
void				minus_button(t_data *d, t_vec2 pos);
int					button_clicked(t_vec2 click, t_vec2 b1, t_vec2 b2);
void				menu_skybox(t_data *d);

#endif
