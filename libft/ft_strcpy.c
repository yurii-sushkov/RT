/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:57:03 by ibarabas          #+#    #+#             */
/*   Updated: 2018/03/27 19:28:23 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*origin;

	origin = dst;
	while (*src != '\0')
		*(dst++) = *(src++);
	*dst = *src;
	return (origin);
}