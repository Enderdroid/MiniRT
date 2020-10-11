/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vec_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:49:02 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:49:03 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"

t_vec3		ft_minus(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}

t_vec3		ft_mult(t_vec3 u, float val)
{
	t_vec3	res;

	res.x = u.x * val;
	res.y = u.y * val;
	res.z = u.z * val;
	return (res);
}

t_vec3		ft_plus(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

float		ft_dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

float		sqrdot(t_vec3 u)
{
	return (u.x * u.x + u.y * u.y + u.z * u.z);
}
