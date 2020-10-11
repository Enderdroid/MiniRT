/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:35:57 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:53:30 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

void				*fill_c(char **sub)
{
	t_cam			*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	cam->id = 5;
	cam->o = vec_parse(sub[1], 'F');
	cam->n = vec_parse(sub[2], 'F');
	cam->fov = ft_atof(sub[3]);
	return (cam);
}

static	float		mix_vec_mult(t_vec3 a, t_vec3 b, t_vec3 c)
{
	int				det;

	det = a.x * b.y * c.z;
	det += a.z * b.x * c.y;
	det += a.y * b.z * c.x;
	det -= a.z * b.y * c.x;
	det -= a.x * b.z * c.y;
	det -= a.y * b.x * c.z;
	return (det);
}

t_vec3				camera(t_res res, t_cam *cam, t_vec3 *v)
{
	float			h;
	t_vec3			del;
	t_vec3			nix;
	t_vec3			niy;

	h = (res.width / 2) * tan(((90 - (cam->fov / 2)) * PI) / 180);
	del = ft_plus(cam->o, ft_mult(cam->n, h));
	if (cam->n.x && !cam->n.y && !cam->n.z)
		niy = get_axis(ft_norm(cam->o, del), ft_fill(0, 0, 1), res.height);
	else
		niy = get_axis(ft_norm(cam->o, del), ft_fill(1, 0, 0), res.height);
	if (niy.y > 0)
		niy = ft_inv(niy);
	if (cam->n.y && !cam->n.x && !cam->n.z)
		nix = get_axis(ft_norm(cam->o, del), ft_fill(0, 0, 1), res.width);
	else
		nix = get_axis(ft_norm(cam->o, del), ft_fill(0, 1, 0), res.width);
	if (get_sign(mix_vec_mult(nix, niy, ft_norm(cam->o, del))) > 1)
		nix = ft_inv(nix);
	sqr_vert_init(v, nix, niy, del);
	cam->nx = ft_norm(cam->v[0], cam->v[2]);
	cam->ny = ft_norm(cam->v[0], cam->v[3]);
	return (cam->o);
}
