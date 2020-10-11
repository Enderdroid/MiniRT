/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:01:10 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:54:54 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINIRT_H
# define LIBMINIRT_H

# include "libincludes.h"
# include "libutils.h"
# include "libvectors.h"

# define PI 3.14159265
# define M_S 10
# define INT_MAX 2147483647
# define MGDA mlx_get_data_addr
# define ESC_CODE 65307
# define A_CODE 97
# define D_CODE 100

typedef struct	s_res
{
	int			id;
	int			width;
	int			height;
}				t_res;
void			*fill_r(char **sub);
typedef struct	s_cam
{
	int			id;
	t_vec3		o;
	t_vec3		n;
	t_vec3		v[4];
	t_vec3		nx;
	t_vec3		ny;
	float		fov;
}				t_cam;
t_vec3			camera(t_res res, t_cam *cam, t_vec3 *v);
void			*fill_c(char **sub);
typedef struct	s_amb
{
	int			id;
	float		rat;
	int			color;
}				t_amb;
void			*fill_a(char **sub, int color);
typedef struct	s_plgt
{
	int			id;
	t_vec3		o;
	float		rat;
	int			color;
}				t_plgt;
void			*fill_l(char **sub, int color);
typedef struct	s_dlgt
{
	int			id;
	t_vec3		o;
	t_vec3		n;
	float		rat;
	int			color;
}				t_dlgt;
typedef struct	s_pln
{
	int			id;
	t_vec3		o;
	t_vec3		n;
	float		t;
}				t_pln;
void			*fill_pl(char **sub);
float			plane(t_ray ray, t_pln pln);
typedef struct	s_sph
{
	int			id;
	t_vec3		c;
	float		d;
	float		r;
	float		t[2];
}				t_sph;
void			*fill_sp(char **sub);
float			sphere(t_ray ray, t_sph sph);
typedef struct	s_sqr
{
	int			id;
	t_vec3		o;
	t_vec3		n;
	float		size;
	float		t;
}				t_sqr;
void			*fill_sq(char **sub);
float			square(t_ray ray, t_sqr sqr);
typedef struct	s_cyl
{
	int			id;
	t_vec3		o;
	t_vec3		n;
	t_vec3		p1;
	t_vec3		p2;
	float		d;
	float		r;
	float		h;
	float		t[4];
}				t_cyl;
void			*fill_cy(char **sub);
float			cylinder(t_ray ray, t_cyl cyl, float *t);
t_vec3			get_cyl_nrm(t_cyl cyl, t_vec3 p);
typedef struct	s_trg
{
	int			id;
	t_vec3		v0;
	t_vec3		v1;
	t_vec3		v2;
	float		t;
}				t_trg;
void			*fill_tr(char **sub);
float			triangle(t_ray ray, t_trg trg);
t_vec3			get_trg_nrm(t_trg trg);
float			ft_intersect(t_list *lst, t_ray ray);
void			ft_draw(t_scene *scene, t_cam c_cam, int ind);
float			dif_lght(t_vec3 n, t_plgt plgt, t_vec3 p);
float			spec_lght(t_vec3 n, t_plgt plgt, t_vec3 p, t_vec3 v);
int				ft_stoint(t_color color);
int				make_shad(int basic, t_vec3 mult);
t_color			vec_to_color(t_vec3 vec);
t_color			fill_color(int r, int g, int b, int a);
t_color			ft_inttos(int color);
int				save_bmp(t_res *res, int **img, char *scene_name, int ind);
float			its_iter(t_scene *scene, t_ray ray, t_list **obj);
float			near_intersect(t_scene *scene, t_ray *ray, t_list **obj);
void			my_mpp(t_data *data, int x, int y, int color);
int				my_pitw(t_vars *vars, t_data *img, int ind, int *i_ind);
int				ft_parser(t_scene *scene, char *file_name);
int				ft_free_scene(t_scene *scene);
int				ft_free_vars(t_vars *vars, t_scene *scene);
t_vec3			get_ratio(t_scene *scene, t_ray ray, t_vec3 r_p, t_vec3 r_n);
void			my_mpp(t_data *data, int x, int y, int color);
int				basic_init(t_scene *scene, int argc, char **argv);
int				my_mlx_hook(int keycode, t_vars *vars);
int				mlx_close(int keycode, t_vars *vars);

#endif
