/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libincludes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:31:08 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:54:37 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBINCLUDES_H
# define LIBINCLUDES_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "liblst.h"

typedef struct	s_vec3 {
	float		x;
	float		y;
	float		z;
}				t_vec3;
typedef struct	s_color {
	int			a;
	int			r;
	int			g;
	int			b;
}				t_color;
typedef struct	s_ray
{
	t_vec3		o;
	t_vec3		d;
	t_vec3		n;
	t_vec3		dir;
}				t_ray;
typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			edn;
}				t_data;
typedef struct	s_scene
{
	t_list		*cam;
	t_list		*prf;
	t_list		*lght;
	void		*res;
	void		*amb;
	int			c_count;
	int			save;
	char		*scene_name;
	int			**grid;
}				t_scene;
typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	int			i_ind;
	int			cam_count;
	t_data		*img;
	t_scene		*scene;
}				t_vars;

#endif
