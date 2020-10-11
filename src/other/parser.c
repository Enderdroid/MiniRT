/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:45:50 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:52:39 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int		id_choise(t_scene *scene, char **arr, int id, int color)
{
	void *content;

	if (id == 0 && (content = fill_pl(arr)))
		ft_lstadd_front(&(scene)->prf, ft_lstnew(content, id, color));
	else if (id == 1 && (content = fill_sp(arr)))
		ft_lstadd_front(&(scene)->prf, ft_lstnew(content, id, color));
	else if (id == 2 && (content = fill_sq(arr)))
		ft_lstadd_front(&(scene)->prf, ft_lstnew(content, id, color));
	else if (id == 3 && (content = fill_cy(arr)))
		ft_lstadd_front(&(scene)->prf, ft_lstnew(content, id, color));
	else if (id == 4 && (content = fill_tr(arr)))
		ft_lstadd_front(&(scene)->prf, ft_lstnew(content, id, color));
	else if (id == 5 && (content = fill_c(arr)))
		ft_lstadd_front(&(scene)->cam, ft_lstnew(content, id, -1));
	else if (id == 6 && (content = fill_l(arr, color)))
		ft_lstadd_front(&(scene)->lght, ft_lstnew(content, id, color));
	else if (id == 7 && (content = fill_r(arr)))
		scene->res = content;
	else if (id == 8 && (content = fill_a(arr, color)))
		scene->amb = content;
	else if (!content)
		return (put_err(4, ft_ctos(id), -1));
	content = NULL;
	return (id);
}

static int		ft_process(char *str, t_scene *scene)
{
	char		**arr;
	int			clr;
	int			id;
	char		s_sym;

	id = -1;
	s_sym = 0;
	while (str[++id])
		if ((str[id] == ' ' || str[id] == '\t') && (s_sym = str[id]))
			break ;
	arr = ft_split(str, s_sym, &id);
	if (!arr)
	{
		ft_delarr(arr, id);
		return (put_err(3, "split->ft_process", -1));
	}
	if (((clr = ft_stoc(arr[0])) <= 4) || clr == 8 || clr == 6)
		clr = ft_stoint(vec_to_color(vec_parse(arr[id - 1], 'I')));
	s_sym = id_choise(scene, arr, ft_stoc(arr[0]), clr);
	ft_delarr(arr, id);
	return (s_sym);
}

static int		str_proc(char *str, t_scene *scene)
{
	int			id;

	if (str[ft_strlen(str) - 1] == 13)
		str[ft_strlen(str) - 1] = 0;
	id = ft_process(str, scene);
	if (id == 5)
		++(scene->c_count);
	return (id);
}

int				ft_parser(t_scene *scene, char *file_name)
{
	int			fd;
	int			ret;
	int			p_ret;
	char		*str;

	fd = open(file_name, O_RDONLY);
	while ((ret = get_next_line(fd, &str)) >= 0)
	{
		if (*str && str[0] != '#' && str[0] != 13)
			p_ret = str_proc(str, scene);
		free(str);
		str = NULL;
		if (ret == 0 || p_ret < 0)
			break ;
	}
	if (ret < 0)
		return (put_err(1, "GNL fault", -1));
	if (p_ret < 0)
		return (-1);
	return (0);
}
