/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:52:07 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:51:42 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

static	int			cyl_pln(float *t, t_ray ray, t_cyl cyl)
{
	t_vec3			c_x;
	t_vec3			nrl;
	float			sqr_k[3];
	float			dis;

	nrl = ft_norm(cyl.p1, cyl.o);
	c_x = ft_minus(ray.o, cyl.p1);
	sqr_k[0] = ft_dot(ray.n, ray.n) - pow(ft_dot(ray.n, nrl), 2);
	sqr_k[1] = 2 * (ft_dot(ray.n, c_x) - ft_dot(ray.n, nrl) * ft_dot(c_x, nrl));
	sqr_k[2] = ft_dot(c_x, c_x) - pow(ft_dot(c_x, nrl), 2) - cyl.r * cyl.r;
	dis = sqr_k[1] * sqr_k[1] - 4 * sqr_k[0] * sqr_k[2];
	if (dis < 0)
		return (1);
	dis = sqrt(dis);
	t[0] = (-sqr_k[1] + dis) / (2 * sqr_k[0]);
	t[1] = (-sqr_k[1] - dis) / (2 * sqr_k[0]);
	return (0);
}

static float		cyl_pln_var(float t_f, t_ray ray, t_cyl cyl)
{
	t_vec3			q;

	q = ft_plus(ray.o, ft_mult(ray.n, t_f));
	if (ft_dot(cyl.n, ft_minus(q, cyl.p1)) > 0 &&
		ft_dot(cyl.n, ft_minus(q, cyl.p2)) < 0)
		return (t_f);
	return (-1);
}

float				cylinder(t_ray ray, t_cyl cyl, float *t)
{
	float			t_f[2];
	float			ret;
	int				i;

	i = -1;
	while (++i < 4)
		cyl.t[i] = -1;
	i = -1;
	while (++i < 2)
		t_f[i] = -1;
	if (cyl_pln(t_f, ray, cyl))
		return (-1);
	if (t_f[0] > 0)
		cyl.t[0] = cyl_pln_var(t_f[0], ray, cyl);
	if (t_f[1] > 0)
		cyl.t[1] = cyl_pln_var(t_f[1], ray, cyl);
	ret = ft_mint(cyl.t, 4);
	i = -1;
	while (++i < 4)
		t[i] = cyl.t[i];
	return (ret);
}
