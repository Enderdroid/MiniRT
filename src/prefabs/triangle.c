/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:52:18 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:52:12 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

void		*fill_tr(char **sub)
{
	t_trg	*trg;

	if (!(trg = (t_trg *)malloc(sizeof(t_trg))))
		return (NULL);
	trg->id = 4;
	trg->v0 = vec_parse(sub[1], 'F');
	trg->v1 = vec_parse(sub[2], 'F');
	trg->v2 = vec_parse(sub[3], 'F');
	return (trg);
}

float		triangle(t_ray ray, t_trg trg)
{
	t_vec3	sub[3];
	t_vec3	vec;
	float	bar[2];
	float	det;

	sub[0] = ft_minus(trg.v1, trg.v0);
	sub[1] = ft_minus(trg.v2, trg.v0);
	sub[2] = ft_cross(ray.n, sub[1]);
	det = ft_dot(sub[0], sub[2]);
	if (!det)
		return (0.0);
	vec = ft_minus(ray.o, trg.v0);
	bar[0] = ft_dot(vec, sub[2]) * (1 / det);
	if (bar[0] < 0 - 0.0001 || bar[0] > 1 + 0.0001)
		return (0.0);
	vec = ft_cross(vec, sub[0]);
	bar[1] = ft_dot(ray.n, vec) * (1 / det);
	if (bar[1] < 0 - 0.0001 || bar[0] + bar[1] > 1 + 0.0001)
		return (0.0);
	return (ft_dot(sub[1], vec) * (1 / det));
}
