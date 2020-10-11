/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:25:02 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:52:31 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

void		*fill_cy(char **sub)
{
	t_cyl	*cyl;

	if (!(cyl = (t_cyl*)malloc(sizeof(t_cyl))))
		return (NULL);
	cyl->id = 3;
	cyl->o = vec_parse(sub[1], 'F');
	cyl->n = vec_parse(sub[2], 'F');
	cyl->n = ft_norm(ft_fill(0, 0, 0), cyl->n);
	cyl->d = ft_atof(sub[3]);
	cyl->r = cyl->d / 2;
	cyl->h = ft_atof(sub[4]);
	cyl->p1 = ft_plus(cyl->o, ft_mult(cyl->n, -cyl->h / 2));
	cyl->p2 = ft_plus(cyl->o, ft_mult(cyl->n, cyl->h / 2));
	return (cyl);
}

void		*fill_l(char **sub, int color)
{
	t_plgt	*plgt;

	if (!(plgt = (t_plgt*)malloc(sizeof(t_plgt))))
		return (NULL);
	plgt->id = 6;
	plgt->o = vec_parse(sub[1], 'F');
	plgt->rat = ft_atof(sub[2]);
	plgt->color = color;
	return (plgt);
}

void		*fill_r(char **sub)
{
	t_res	*res;

	if (!(res = (t_res*)malloc(sizeof(t_res))))
		return (NULL);
	res->id = 7;
	if ((res->width = atoi(sub[1])) > 1920)
		res->width = 1920;
	if ((res->height = atoi(sub[2])) > 1080)
		res->height = 1080;
	return (res);
}

void		*fill_a(char **sub, int color)
{
	t_amb	*amb;

	if (!(amb = (t_amb*)malloc(sizeof(t_amb))))
		return (NULL);
	amb->id = 8;
	amb->rat = ft_atof(sub[1]);
	amb->color = color;
	return (amb);
}
