/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:48:13 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:16 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

int				mlx_close(int keycode, t_vars *vars)
{
	free_data(vars, NULL);
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}

int				my_pitw(t_vars *vars, t_data *img, int ind, int *i_ind)
{
	if (i_ind)
		*i_ind = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, img[ind].img, 0, 0);
	return (1);
}

int				sto_img(t_data *img, t_vars *vars, t_scene *scene)
{
	t_res		*res;
	int			x;
	int			y;

	res = (t_res *)scene->res;
	img->img = mlx_new_image(vars->mlx, res->width, res->height);
	img->addr = MGDA(img->img, &img->bpp, &img->ll, &img->edn);
	x = -1;
	while (++x < res->width)
	{
		y = -1;
		while (++y < res->height)
			my_mpp(img, x, y, scene->grid[x][y]);
		free(scene->grid[x]);
	}
	free(scene->grid);
	return (1);
}

int				vars_init(t_vars *vars, t_data **img,
							t_scene scene, t_list **c_buf)
{
	t_res		*res;

	res = (t_res*)scene.res;
	if (!scene.save)
	{
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, res->width,
									res->height, "MiniRT");
		vars->cam_count = scene.c_count;
		if (!(*img = (t_data *)malloc(sizeof(t_data) * scene.c_count)))
			return (put_err(3, "main->vars_init", 1));
		vars->img = *img;
	}
	else
		*img = NULL;
	*c_buf = scene.cam;
	vars->i_ind = 0;
	return (0);
}

int				main(int argc, char *argv[])
{
	t_vars		vars;
	t_data		*img;
	t_scene		scene;
	t_list		*c_buf;

	if (basic_init(&scene, argc, argv) ||
					rt_validate(argv) || ft_parser(&scene, argv[1]))
		return (free_data(NULL, &scene));
	if (vars_init(&vars, &img, scene, &c_buf))
		return (free_data(&vars, &scene));
	while (c_buf)
	{
		ft_draw(&scene, *((t_cam *)c_buf->content), (vars.i_ind)++);
		if (!scene.save)
			img += sto_img(img, &vars, &scene);
		c_buf = c_buf->next;
	}
	free_data(NULL, &scene);
	if (!scene.save && my_pitw(&vars, vars.img, 0, &vars.i_ind))
	{
		mlx_hook(vars.win, 17, 1L << 17, mlx_close, &vars);
		mlx_key_hook(vars.win, my_mlx_hook, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
