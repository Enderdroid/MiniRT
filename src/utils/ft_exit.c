/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:50:11 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:50:14 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"
#include <unistd.h>

int			free_data(t_vars *vars, t_scene *scene)
{
	if (scene)
	{
		if (&scene->cam)
			ft_lstclear(&scene->cam);
		if (&scene->prf)
			ft_lstclear(&scene->prf);
		if (&scene->lght)
			ft_lstclear(&scene->lght);
		if (scene->res)
			free(scene->res);
		if (scene->amb)
			free(scene->amb);
	}
	if (vars && vars->img)
		free(vars->img);
	return (1);
}

void		put_str(const char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}

void		print_err(const char *err, const char *data)
{
	char	*f_err;

	if (err)
	{
		f_err = ft_strjoin("Error\n", err);
		if (!f_err)
			put_str("Error\nbad alloc in print_error\n", 1);
		put_str(f_err, 1);
		free(f_err);
	}
	if (data)
	{
		write(1, " [", 2);
		put_str(data, 1);
		write(1, "]", 1);
	}
}

int			put_row(int row)
{
	char	*str_row;
	size_t	i;

	str_row = ft_itoa(row);
	if (!str_row)
	{
		write(1, "[nan]", 5);
		return (-1);
	}
	i = ft_strlen(str_row);
	write(1, "row = [", 7);
	write(1, str_row, i);
	write(1, "]\n", 2);
	return (-1);
}

int			put_err(int err_code, char *data, int ret)
{
	if (err_code == 0)
		print_err("basicInit", data);
	if (err_code == 1)
		print_err("in rtValidate", data);
	if (err_code == 2)
		print_err("in scene config", data);
	if (err_code == 3)
		print_err("Bad alloc in", data);
	if (err_code == 4)
		print_err("Bad alloc while parse obj:", data);
	if (err_code == 5)
		print_err("Failed to open file", data);
	if (err_code == 6)
		print_err("While creating bmp", data);
	put_str("\n", 1);
	return (ret);
}
