/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:41:55 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 06:42:22 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	r_size;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	r_size = s_len + d_len;
	if (d_len >= size)
		r_size = s_len + size;
	while (src[i] != '\0' && d_len + 1 < size)
		dst[d_len++] = src[i++];
	if (i)
		dst[d_len] = '\0';
	return (r_size);
}
