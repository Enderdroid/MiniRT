/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:40:49 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 05:43:16 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		*g_memset(void *destination, int c, size_t n)
{
	char		*dst;
	size_t		i;

	dst = destination;
	i = 0;
	while (i < n)
	{
		dst[i] = c;
		++i;
	}
	return (dst);
}

static void		*g_calloc(size_t num, size_t size)
{
	void		*alloc;

	alloc = malloc(num * size);
	if (!alloc)
		return (NULL);
	g_memset(alloc, 0, num * size);
	return (alloc);
}

size_t			g_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		++i;
	return (i);
}

static size_t	g_strlcat(char *dst, const char *src, size_t size)
{
	size_t		s_len;
	size_t		d_len;
	size_t		r_size;
	size_t		i;

	i = 0;
	s_len = g_strlen(src);
	d_len = g_strlen(dst);
	r_size = s_len + d_len;
	if (d_len >= size)
		r_size = s_len + size;
	while (src[i] != '\0' && d_len + 1 < size)
		dst[d_len++] = src[i++];
	if (i)
		dst[d_len] = '\0';
	return (r_size);
}

char			*g_strjoin(char *s1, char const *s2)
{
	size_t		f_len;
	size_t		s_len;
	char		*str_j;

	f_len = 0;
	if (s1)
		f_len = g_strlen(s1);
	s_len = g_strlen(s2);
	str_j = g_calloc(f_len + s_len + 1, sizeof(char));
	if (str_j == NULL)
		return (NULL);
	if (f_len + s_len == 0)
		str_j[0] = 0;
	else
	{
		if (s1)
			g_strlcat(str_j, s1, f_len + s_len + 1);
		g_strlcat(str_j, s2, f_len + s_len + 1);
	}
	if (s1)
		free(s1);
	return (str_j);
}
