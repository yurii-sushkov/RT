/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:06:06 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/17 15:01:39 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Сравнивает первое слово строки со всеми знакомыми словами.
**	Если что-то находит, то передает содержимое строки
**	в соответствующую функцию.
**	Все проверки на ошибки происходят уже в отдельных функциях.
*/

void	parse_line(t_data *d, char **arr)
{
	if (!ft_strcmp(arr[0], "sphere"))
		new_object(d, 1);
	else if (!ft_strcmp(arr[0], "plane"))
		new_object(d, 2);
	else if (!ft_strcmp(arr[0], "cylinder"))
		new_object(d, 3);
	else if (!ft_strcmp(arr[0], "cone"))
		new_object(d, 4);
	else if (!ft_strcmp(arr[0], "disk"))
		new_object(d, 5);
	else if (!ft_strcmp(arr[0], "box"))
		new_object(d, 6);
	else if (!ft_strcmp(arr[0], "position:"))
		set_position(d, arr);
	else if (!ft_strcmp(arr[0], "rotation:")
		|| !ft_strcmp(arr[0], "direction:"))
		set_rotation(d, arr);
	else if (!ft_strcmp(arr[0], "scale:"))
		set_scale(d, arr);
	else if (!ft_strcmp(arr[0], "color:"))
		set_color(d, arr);
	else
		parse_line_2(d, arr);
}

/*
**	Функция разбита на три части.
**	Все мы знаем, почему.
*/

void	parse_line_3(t_data *d, char **arr)
{
	if (!ft_strcmp(arr[0], "no_skybox"))
		d->skybox = 0;
	else if (!ft_strcmp(arr[0], "light:"))
		add_light(d, arr, 0);
	else if (!ft_strcmp(arr[0], "metallic"))
		set_metallic(d);
}

void	parse_line_2(t_data *d, char **arr)
{
	if (!ft_strcmp(arr[0], "camera:"))
		set_camera(d, arr);
	else if (!ft_strcmp(arr[0], "reflective:"))
		set_reflective(d, arr);
	else if (!ft_strcmp(arr[0], "reflection-depth:"))
		set_depth(d, arr);
	else if (!ft_strcmp(arr[0], "length:"))
		set_length(d, arr);
	else if (!ft_strcmp(arr[0], "ambient:"))
		set_ambient(d, arr);
	else if (!ft_strcmp(arr[0], "shine:"))
		set_shine(d, arr);
	else if (!ft_strcmp(arr[0], "transparency:"))
		set_transparency(d, arr);
	else if (!ft_strcmp(arr[0], "radius:"))
		set_radius(d, arr);
	else if (!ft_strcmp(arr[0], "directional_light:"))
		add_light(d, arr, 1);
	else if (!ft_strcmp(arr[0], "lamp:"))
		add_lamp(d, arr);
	else
		parse_line_3(d, arr);
}

/*
**	Если первый же вызов GNL возвращает 0 или -1,
**	то файл неправильный или совершенно пустой
*/

void	handle_empty_file(int gnl_return)
{
	static int	was_already_checked;

	if (!was_already_checked && gnl_return <= 0)
		ft_error("Error: invalid file");
	was_already_checked = 1;
}

/*
**	Построчно читает файл функцией parse_line()
*/

int		read_file(t_data *d, int fd)
{
	char	*line;
	char	**arr;
	int		i;
	int		return_value;

	while ((return_value = get_next_line(fd, &line)) > 0)
	{
		handle_empty_file(return_value);
		arr = ft_strsplit(line, ' ');
		if (arr[0])
		{
			parse_line(d, arr);
		}
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		free(line);
	}
	return (1);
}
