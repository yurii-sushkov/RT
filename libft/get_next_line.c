/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:32:03 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/20 14:24:22 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Ищет буфер, соответствующий данному файловому дескриптору
**	Присваивает его адрес указателю *buff, если нашелся
*/

int		search(int fd, t_buff *list, t_buff **buff)
{
	while (list->next)
	{
		if (list->fd == fd)
		{
			*buff = list;
			break ;
		}
		list = list->next;
	}
	if (list->fd == fd)
		*buff = list;
	else
	{
		if (!(list->next = (t_buff *)malloc(sizeof(t_buff))))
			return (-1);
		list->next->fd = fd;
		list->next->next = 0;
		list->next->prev = list;
		if (!(list->next->content = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
		*(list->next->content) = '\0';
		*buff = list->next;
	}
	return (1);
}

/*
**	Находит или создаёт буфер для данного файлового дескриптора,
**	выделяет строку размером в BUFF_SIZE + 1,
**	и присваивает адрес структуры-буфера указателю *buff
*/

int		get_buff(int fd, t_buff **bufflist, t_buff **buff)
{
	t_buff	*list;

	list = *bufflist;
	if (!list)
	{
		if (!(*bufflist = (t_buff *)malloc(sizeof(t_buff))))
			return (-1);
		(*bufflist)->fd = fd;
		(*bufflist)->next = 0;
		(*bufflist)->prev = 0;
		if (!((*bufflist)->content = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
		*((*bufflist)->content) = '\0';
		*buff = *bufflist;
	}
	else if (search(fd, list, buff) == -1)
		return (-1);
	return (1);
}

/*
**	Копирует всё, что находится после '\n'
**	(часть следующей строки, попавшая в предыдущий буфер)
*/

void	init_nextline(t_buff *buff, char **nextline)
{
	char	*temp;

	temp = ft_strchr(buff->content, 10);
	if (temp)
	{
		*nextline = ft_strdup(++temp);
		ft_strcpy(buff->content, temp);
	}
	else
		*nextline = ft_strnew(1);
}

/*
**	Читает из fd и добавляет прочитанное к *nextline,
**	пока *nextline не будет содержать '\n'
*/

int		main_loop(int n, char **nextline, t_buff *buff, char *temp)
{
	while (!ft_strchr(*nextline, 10))
	{
		n = read(buff->fd, buff->content, BUFF_SIZE);
		if (n == 0)
		{
			if (!(*nextline))
			{
				if (buff->next)
					buff->next->prev = buff->prev;
				if (buff->prev)
					buff->prev->next = buff->next;
				free(buff->content);
				free(buff);
			}
			return (0);
		}
		if (n < 0)
			return (-1);
		(buff->content)[n] = '\0';
		temp = *nextline;
		*nextline = ft_strjoin(*nextline, buff->content);
		free(temp);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	*bufflist;
	t_buff			*buff;
	char			*nextline;
	char			*temp;
	int				rvalue;

	if (get_buff(fd, &bufflist, &buff) == -1 || !line)
		return (-1);
	init_nextline(buff, &nextline);
	rvalue = main_loop(0, &nextline, buff, NULL);
	if (rvalue == -1)
		return (-1);
	if (rvalue == 0 && !(*nextline))
	{
		free(nextline);
		return (0);
	}
	if (ft_strchr(nextline, 10) && rvalue > 0)
	{
		temp = nextline;
		nextline = ft_strsub(nextline, 0, ft_strlen_delim(nextline, 10));
		free(temp);
	}
	*line = nextline;
	return (1);
}
