/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:57:57 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/07 22:55:03 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

int			my_mlx_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_CODE)
		mlx_close(keycode, vars);
	if (keycode == A_CODE)
	{
		if (vars->i_ind < vars->cam_count - 1)
			++(vars->i_ind);
		else
			vars->i_ind = 0;
	}
	if (keycode == D_CODE)
	{
		if (vars->i_ind > 0)
			--(vars->i_ind);
		else
			vars->i_ind = vars->cam_count - 1;
	}
	if (keycode == A_CODE || keycode == D_CODE)
		my_pitw(vars, vars->img, vars->i_ind, NULL);
	return (0);
}

void		my_mpp(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int			basic_init(t_scene *scene, int argc, char **argv)
{
	int		len;

	scene->res = NULL;
	scene->amb = NULL;
	scene->cam = NULL;
	scene->prf = NULL;
	scene->lght = NULL;
	scene->c_count = 0;
	scene->save = 0;
	scene->grid = NULL;
	if (argc < 2 || argc > 3)
		return (put_err(0, "flags count", 1));
	len = ft_strlen(argv[1]);
	if (ft_strcmp(&argv[1][len - 3], ".rt"))
		return (put_err(0, "rt extension", 1));
	scene->scene_name = argv[1];
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (put_err(0, "second flag", 1));
	if (argc == 3)
		scene->save = 1;
	return (0);
}
