/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:49:55 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:49:57 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static int		ft_getsize(char const *s, char c)
{
	int			size;
	int			i;

	i = 0;
	if (!s || *s == '\0')
		return (1);
	while (s[i] == c)
		++i;
	if (s[i] == '\0')
		return (1);
	size = 0;
	while (s[++i] != '\0')
		if (s[i] == c && s[i - 1] != c)
			++size;
	if (s[i - 1] != c)
		++size;
	return (size + 1);
}

static int		ft_arrfill(char **arr, char const *s, char c, int i)
{
	int			j;

	j = 0;
	while (*s != c && *s)
		arr[i][j++] = (char)*s++;
	arr[i][j] = 0;
	return (j);
}

static int		ft_getlen(char const *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s)
	{
		++len;
		++s;
	}
	++len;
	return (len);
}

char			**ft_split(char const *s, char c, int *size)
{
	char		**arr;

	*size = 0;
	if (!s || !c || !(arr = malloc(ft_getsize(s, c) * sizeof(char*))))
		return (NULL);
	arr[ft_getsize(s, c) - 1] = NULL;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s != c && *s)
		{
			if (!(arr[*size] = malloc(ft_getlen(s, c) * sizeof(char))))
			{
				ft_delarr(arr, *size);
				return (NULL);
			}
			s += ft_arrfill(arr, s, c, *size);
			++(*size);
		}
	}
	return (arr);
}
