/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:52:16 by ibarabas          #+#    #+#             */
/*   Updated: 2018/05/21 08:11:13 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	new_img(t_win *win, t_img *img)
{
	void	*p;

	img->id = mlx_new_image(win->mlx, win->size.x, win->size.y);
	p = mlx_get_data_addr(img->id, &(img->bpp), &(img->len), &(img->endian));
	img->addr = p;
}
