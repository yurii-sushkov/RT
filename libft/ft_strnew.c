/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:46:12 by ibarabas          #+#    #+#             */
/*   Updated: 2018/04/01 08:56:08 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	void	*vstr;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	vstr = (void *)str;
	ft_bzero(vstr, size + 1);
	return (str);
}
