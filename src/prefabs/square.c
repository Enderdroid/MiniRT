/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:52:14 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:52:05 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

void		*fill_sq(char **sub)
{
	t_sqr	*sqr;

	if (!(sqr = (t_sqr *)malloc(sizeof(t_sqr))))
		return (NULL);
	sqr->id = 2;
	sqr->o = vec_parse(sub[1], 'F');
	sqr->n = vec_parse(sub[2], 'F');
	sqr->size = ft_atof(sub[3]);
	return (sqr);
}

float		square(t_ray ray, t_sqr sqr)
{
	t_vec3	v[4];
	t_trg	pol;
	t_vec3	nix;
	t_vec3	niy;
	float	t;

	if (sqr.n.x && !sqr.n.y && !sqr.n.z)
		niy = get_axis(sqr.n, ft_fill(0, 0, 1), sqr.size);
	else
		niy = get_axis(sqr.n, ft_fill(1, 0, 0), sqr.size);
	if (sqr.n.y && !sqr.n.x && !sqr.n.z)
		nix = get_axis(sqr.n, ft_fill(0, 0, 1), sqr.size);
	else
		nix = get_axis(sqr.n, ft_fill(0, 1, 0), sqr.size);
	sqr_vert_init(v, nix, niy, sqr.o);
	pol.v0 = v[0];
	pol.v1 = v[2];
	pol.v2 = v[3];
	if ((t = triangle(ray, pol)))
		return (t);
	pol.v0 = v[1];
	if ((t = triangle(ray, pol)))
		return (t);
	return (0.0);
}
