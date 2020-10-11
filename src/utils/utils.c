/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:49:26 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:49:27 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int				ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int				get_sign(float f)
{
	if (f > 0)
		return (1);
	if (f < 0)
		return (-1);
	return (0);
}

void			*ft_memset(void *destination, int c, size_t n)
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

void			*ft_calloc(size_t num, size_t size)
{
	void		*alloc;

	alloc = malloc(num * size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, num * size);
	return (alloc);
}

int				**crt_mtx(int x, int y)
{
	int			**arr;
	int			ind;

	arr = (int **)malloc(sizeof(int *) * x);
	ind = 0;
	while (ind < x)
		arr[ind++] = ft_calloc(y, sizeof(int));
	return (arr);
}
