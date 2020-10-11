/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:15:44 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:51:10 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

float		dif_lght(t_vec3 dl_n, t_plgt plgt, t_vec3 dl_p)
{
	t_vec3	dl_l;
	float	n_rat;

	dl_l = ft_norm(dl_p, plgt.o);
	n_rat = ft_dot(dl_n, dl_l);
	if (n_rat < 0 || (dl_n.x == 0 && dl_n.y == 0 && dl_n.z == 0))
		return (0);
	n_rat /= sqrt(sqrdot(dl_n)) * sqrt(sqrdot(dl_l));
	return (n_rat);
}

float		spec_lght(t_vec3 sl_n, t_plgt plgt, t_vec3 sl_p, t_vec3 sl_v)
{
	t_vec3	sl_l;
	t_vec3	sl_r;
	float	n_rat;

	sl_l = ft_norm(sl_p, plgt.o);
	sl_r = ft_minus(ft_mult(sl_n, ft_dot(sl_n, sl_l) * 2), sl_l);
	n_rat = ft_dot(sl_r, sl_v);
	if (n_rat < 0 || (sl_n.x == 0 && sl_n.y == 0 && sl_n.z == 0))
		return (0);
	n_rat /= sqrt(sqrdot(sl_r)) * sqrt(sqrdot(sl_v));
	return (n_rat);
}

t_vec3		get_trg_nrm(t_trg trg)
{
	t_vec3	n;
	float	a;
	float	b;
	float	c;

	a = (trg.v1.y - trg.v0.y) * (trg.v2.z - trg.v0.z) -
		(trg.v2.y - trg.v0.y) * (trg.v1.z - trg.v0.z);
	b = -1 * ((trg.v1.x - trg.v0.x) * (trg.v2.z - trg.v0.z) -
		(trg.v2.x - trg.v0.x) * (trg.v1.z - trg.v0.z));
	c = (trg.v1.x - trg.v0.x) * (trg.v2.y - trg.v0.y) -
		(trg.v2.x - trg.v0.x) * (trg.v1.y - trg.v0.y);
	n = ft_fill(a, b, c);
	return (n);
}

t_vec3		get_cyl_nrm(t_cyl cyl, t_vec3 c_p)
{
	t_vec3	p1;
	float	buf;
	t_vec3	c_n;
	t_pln	pln;
	t_ray	o_ray;

	pln.o = c_p;
	pln.n = cyl.n;
	o_ray.o = cyl.p1;
	o_ray.n = cyl.n;
	if (cyl.t[2] > 0 || cyl.t[3] > 0)
	{
		if (cyl.t[2] > 0)
			c_n = ft_inv(cyl.n);
		if (cyl.t[3] > 0)
			c_n = cyl.n;
	}
	else if ((buf = plane(o_ray, pln)))
		p1 = ft_plus(o_ray.o, ft_mult(o_ray.n, buf));
	else
		return (ft_fill(0, 0, 0));
	c_n = ft_norm(p1, c_p);
	return (c_n);
}
