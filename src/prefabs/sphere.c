/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:52:12 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:51:57 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

static float	ft_min(float a, float b)
{
	return (a < b ? a : b);
}

static float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

void			*fill_sp(char **sub)
{
	t_sph		*sph;

	if (!(sph = (t_sph *)malloc(sizeof(t_sph))))
		return (NULL);
	sph->id = 1;
	sph->c = vec_parse(sub[1], 'F');
	sph->d = ft_atof(sub[2]);
	sph->r = sph->d / 2;
	return (sph);
}

float			sphere(t_ray ray, t_sph sph)
{
	t_vec3		k;
	float		d;
	float		t[3];

	k = ft_minus(ray.o, sph.c);
	d = pow(ft_dot(k, ray.n), 2) - sqrdot(k) + pow(sph.r, 2);
	if (d >= 0)
	{
		t[1] = -ft_dot(k, ray.n) + sqrt(d);
		t[2] = -ft_dot(k, ray.n) - sqrt(d);
		if ((t[0] = ft_min(t[1], t[2])) >= 0)
			return (t[0]);
		else
			return (ft_max(t[1], t[2]));
	}
	return (0.0);
}
