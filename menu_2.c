/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:17 by ibarabas          #+#    #+#             */
/*   Updated: 2018/07/28 11:40:18 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		button_clicked(t_vec2 click, t_vec2 b1, t_vec2 b2)
{
	if (click.x >= b1.x && click.x <= b2.x
		&& click.y >= b1.y && click.y <= b2.y)
		return (1);
	return (0);
}

void	menu_skybox(t_data *d)
{
	put_text(d, vec2(15, 120), rgb_to_int(212, 210, 106), "Skybox:");
	if (d->skybox)
	{
		draw_rect(d, vec2(110, 120), vec2(150, 145), tcol(149, 117, 171, 100));
		put_text(d, vec2(120, 120), rgb_to_int(255, 253, 170), "On");
		put_text(d, vec2(180, 120), rgb_to_int(212, 210, 106), "Off");
	}
	else
	{
		draw_rect(d, vec2(170, 120), vec2(220, 145), tcol(149, 117, 171, 100));
		put_text(d, vec2(120, 120), rgb_to_int(212, 210, 106), "On");
		put_text(d, vec2(180, 120), rgb_to_int(255, 253, 170), "Off");
	}
}
