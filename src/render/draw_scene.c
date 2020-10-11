/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:15:39 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:50:37 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

static int		draw_color(t_scene *scene, t_ray ray, t_list *buf, float t)
{
	t_vec3		c_n;
	t_vec3		c_p;
	t_vec3		rat;

	c_p = ft_plus(ray.o, ft_mult(ray.n, t));
	if (buf->id == 0)
		c_n = ((t_pln*)buf->content)->n;
	else if (buf->id == 1)
		c_n = ft_norm(((t_sph*)buf->content)->c, c_p);
	else if (buf->id == 2)
		c_n = ((t_sqr*)buf->content)->n;
	else if (buf->id == 3)
		c_n = get_cyl_nrm(*((t_cyl*)buf->content), c_p);
	else if (buf->id == 4)
		c_n = get_trg_nrm(*((t_trg*)buf->content));
	rat = get_ratio(scene, ray, c_p, c_n);
	return (make_shad(buf->color, rat));
}

void			ft_draw(t_scene *scene, t_cam c_cam, int ind)
{
	t_ray		ray;
	float		t;
	t_list		*obj;
	int			i[2];
	t_res		*res;

	i[0] = -1;
	res = (t_res*)scene->res;
	scene->grid = crt_mtx(res->width, res->height);
	ray.o = camera(*res, &c_cam, c_cam.v);
	while ((++i[0]) < res->width)
	{
		i[1] = -1;
		while ((++i[1]) < res->height)
		{
			obj = NULL;
			ray.d = ft_plus(ft_mult(c_cam.nx, i[0]), ft_mult(c_cam.ny, i[1]));
			ray.d = ft_plus(ray.d, c_cam.v[0]);
			t = near_intersect(scene, &ray, &obj);
			if (t > 0 && obj)
				scene->grid[i[0]][i[1]] = draw_color(scene, ray, obj, t);
		}
	}
	if (scene->save)
		save_bmp(res, scene->grid, scene->scene_name, ind);
}
