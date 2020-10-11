/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ratio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:14:28 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:50:46 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

static t_vec3	get_itc(t_vec3 i_p, t_vec3 i_n, t_vec3 i_nr, t_plgt *plgt)
{
	t_color		color;
	float		ret_buf;
	t_vec3		rat;

	color = ft_inttos(plgt->color);
	ret_buf = (dif_lght(i_n, *plgt, i_p) +
				pow(spec_lght(i_n, *plgt, i_p, i_nr), M_S)) *
				plgt->rat;
	rat.x = color.r * ret_buf / 255;
	rat.y = color.g * ret_buf / 255;
	rat.z = color.b * ret_buf / 255;
	return (rat);
}

static t_vec3	do_amb(t_vec3 rat, t_amb *amb)
{
	t_color		color;

	color = ft_inttos(amb->color);
	rat.x += (amb->rat * color.r / 255);
	rat.y += (amb->rat * color.g / 255);
	rat.z += (amb->rat * color.b / 255);
	if (rat.x > 1)
		rat.x = 1;
	if (rat.y > 1)
		rat.y = 1;
	if (rat.z > 1)
		rat.z = 1;
	return (rat);
}

static int		get_rat_init(t_list **plgt, t_scene **scene,
							t_ray *ray, t_vec3 *rat)
{
	*plgt = (t_list *)(*scene)->lght;
	*rat = ft_fill(0, 0, 0);
	ray->n = ft_norm(ray->o, ray->d);
	return (1);
}

static float	sub_get_rat(t_list **plgt, t_plgt **lght,
							t_scene **scene, t_ray *l_ray)
{
	float		buf;

	*lght = (t_plgt *)(*plgt)->content;
	(*l_ray).o = (*lght)->o;
	buf = near_intersect(*scene, l_ray, NULL);
	(*l_ray).n = ft_norm((*l_ray).o, (*l_ray).d);
	return (buf);
}

t_vec3			get_ratio(t_scene *scene, t_ray ray, t_vec3 r_p, t_vec3 r_n)
{
	t_ray		l_ray;
	float		buf[2];
	t_vec3		rat;
	t_list		*plgt;
	t_plgt		*lght;

	l_ray.d = ft_mult(r_p, get_rat_init(&plgt, &scene, &ray, &rat));
	while (plgt)
	{
		buf[0] = sub_get_rat(&plgt, &lght, &scene, &l_ray);
		buf[1] = ft_dist(r_p, lght->o);
		if (buf[0] + 0.1 >= buf[1] && buf[0] - 0.1 < buf[1])
			if (get_sign(ft_dot(l_ray.n, r_n)) == get_sign(ft_dot(ray.n, r_n)))
			{
				if (ft_dot(l_ray.n, r_n) > 0)
					rat = ft_plus(rat, get_itc(r_p, ft_inv(r_n),
							ft_norm(r_p, ray.o), lght));
				else
					rat = ft_plus(rat, get_itc(r_p, r_n,
							ft_norm(r_p, ray.o), lght));
			}
		plgt = plgt->next;
	}
	return (do_amb(rat, (t_amb *)scene->amb));
}
