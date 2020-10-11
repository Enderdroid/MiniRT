/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:52:09 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:51:49 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

void		*fill_pl(char **sub)
{
	t_pln	*pln;

	if (!(pln = (t_pln *)malloc(sizeof(t_pln))))
		return (NULL);
	pln->id = 0;
	pln->o = vec_parse(sub[1], 'F');
	pln->n = vec_parse(sub[2], 'F');
	return (pln);
}

float		plane(t_ray ray, t_pln pln)
{
	float	a;
	float	b;
	float	t;
	float	pl_d;

	pl_d = -(pln.n.x * pln.o.x + pln.n.y * pln.o.y + pln.n.z * pln.o.z);
	a = ft_dot(pln.n, ray.n);
	if (a == 0)
		return (0.0);
	b = pln.n.x * ray.o.x + pln.n.y * ray.o.y + pln.n.z * ray.o.z + pl_d;
	t = (-b) / a;
	if (t > 0)
		return (t);
	return (0.0);
}
