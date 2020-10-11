/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:48:51 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:53 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

float		ft_mint(float *t, int size)
{
	float	min_len;
	int		k;
	int		i;

	min_len = -1;
	i = -1;
	while (++i < size)
	{
		if (t[i] > 0 && (min_len > t[i] || min_len < 0))
		{
			min_len = t[i];
			k = i;
		}
		if (t[i] > 0)
			t[i] *= -1;
	}
	if (min_len < 0)
		return (-1);
	if (t[k] < 0)
		t[k] *= -1;
	return (min_len);
}

float		ft_dist(t_vec3 v, t_vec3 u)
{
	float	buf;

	buf = pow(u.x - v.x, 2) + pow(u.y - v.y, 2) + pow(u.z - v.z, 2);
	return (sqrt(buf));
}

t_vec3		ft_norm(t_vec3 u, t_vec3 v)
{
	t_vec3	res;
	float	len;

	res.x = v.x - u.x;
	res.y = v.y - u.y;
	res.z = v.z - u.z;
	len = ft_dist(v, u);
	res.x /= len;
	res.y /= len;
	res.z /= len;
	return (res);
}
