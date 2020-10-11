/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:48:31 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:33 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

t_vec3		get_axis(t_vec3 dest, t_vec3 pln, float len)
{
	t_vec3	res;

	len = len / 2;
	res = ft_cross(dest, pln);
	res = ft_mult(ft_norm(ft_fill(0, 0, 0), res), len);
	return (res);
}

void		sqr_vert_init(t_vec3 *v, t_vec3 nix, t_vec3 niy, t_vec3 o)
{
	int		ind;

	v[0] = ft_plus(nix, niy);
	v[1] = ft_plus(ft_inv(nix), ft_inv(niy));
	v[2] = ft_plus(ft_inv(nix), niy);
	v[3] = ft_plus(nix, ft_inv(niy));
	ind = -1;
	while (++ind < 4)
		v[ind] = ft_plus(v[ind], o);
}

t_vec3		ft_fill(float x, float y, float z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3		ft_inv(t_vec3 v)
{
	t_vec3	res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}

t_vec3		ft_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
