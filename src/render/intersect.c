/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:15:42 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:50:58 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

float		ft_intersect(t_list *lst, t_ray ray)
{
	float	t;

	t = 0;
	if (((t_list*)lst)->id == 0)
		t = plane(ray, *((t_pln*)lst->content));
	else if (((t_list*)lst)->id == 1)
		t = sphere(ray, *((t_sph*)lst->content));
	else if (((t_list*)lst)->id == 2)
		t = square(ray, *((t_sqr*)lst->content));
	else if (((t_list*)lst)->id == 3)
		t = cylinder(ray, *((t_cyl*)lst->content), (*((t_cyl*)lst->content)).t);
	else if (((t_list*)lst)->id == 4)
		t = triangle(ray, *((t_trg*)lst->content));
	return (t);
}

float		its_iter(t_scene *scene, t_ray ray, t_list **obj)
{
	float	obj_t;
	float	buf;
	t_list	*l_buf;

	if (!scene->prf)
		return (0);
	l_buf = scene->prf;
	obj_t = INT_MAX;
	while (l_buf)
	{
		if ((buf = ft_intersect(l_buf, ray)) > 0 && buf < obj_t)
		{
			obj_t = buf;
			if (obj)
				*obj = l_buf;
		}
		l_buf = l_buf->next;
	}
	if (obj_t == INT_MAX)
		obj_t = 0;
	return (obj_t);
}

float		near_intersect(t_scene *scene, t_ray *ray, t_list **obj)
{
	float	obj_t;

	obj_t = 0;
	ray->n = ft_norm(ray->o, ray->d);
	obj_t = its_iter(scene, *ray, obj);
	return (obj_t);
}
