/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:32:01 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/20 18:31:58 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000

# include "libft.h"

typedef struct		s_buff
{
	char			*content;
	int				fd;
	struct s_buff	*next;
	struct s_buff	*prev;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
