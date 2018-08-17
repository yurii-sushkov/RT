/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:56:44 by ibarabas          #+#    #+#             */
/*   Updated: 2018/05/21 14:01:16 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <math.h>

double	vec2len(t_vec2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

double	vec2flen(t_vec2f vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}
