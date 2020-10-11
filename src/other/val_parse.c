/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:26:31 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:53:08 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvectors.h"
#include "libutils.h"

int			ft_stoc(char *str)
{
	if (!ft_strcmp(str, "pl"))
		return (0);
	if (!ft_strcmp(str, "sp"))
		return (1);
	if (!ft_strcmp(str, "sq"))
		return (2);
	if (!ft_strcmp(str, "cy"))
		return (3);
	if (!ft_strcmp(str, "tr"))
		return (4);
	if (!ft_strcmp(str, "c"))
		return (5);
	if (!ft_strcmp(str, "l"))
		return (6);
	if (!ft_strcmp(str, "R"))
		return (7);
	if (!ft_strcmp(str, "A"))
		return (8);
	return (-1);
}

char		*ft_ctos(int id)
{
	if (id == 0)
		return ("pl");
	if (id == 1)
		return ("sp");
	if (id == 2)
		return ("sq");
	if (id == 3)
		return ("cy");
	if (id == 4)
		return ("tr");
	if (id == 5)
		return ("c");
	if (id == 6)
		return ("l");
	if (id == 7)
		return ("R");
	if (id == 8)
		return ("A");
	return ("non");
}

int			id_check(char **arr, char id, int buf)
{
	int		ret;

	ret = -3;
	if (id == 0 && buf == 4)
		ret = val_order(arr, "FNI");
	else if (id == 1 && buf == 4)
		ret = val_order(arr, "FfI");
	else if (id == 2 && buf == 5)
		ret = val_order(arr, "FNfI");
	else if (id == 3 && buf == 6)
		ret = val_order(arr, "FNffI");
	else if (id == 4 && buf == 5)
		ret = val_order(arr, "FFFI");
	else if (id == 5 && buf == 4)
		ret = val_order(arr, "FNf");
	else if (id == 6 && buf == 4)
		ret = val_order(arr, "FfI");
	else if (id == 7 && buf == 3)
		ret = val_order(arr, "ii");
	else if (id == 8 && buf == 3)
		ret = val_order(arr, "fI");
	else
		ret = put_err(2, "undefined error", -1);
	return (ret);
}

t_vec3		vec_parse(char *str, const char type)
{
	char	**ax;
	t_vec3	vec;
	int		ind;

	ind = 0;
	ax = ft_split(str, ',', &ind);
	if (type == 'f' || type == 'F')
		vec = ft_fill(ft_atof(ax[0]), ft_atof(ax[1]), ft_atof(ax[2]));
	if (type == 'i' || type == 'I')
		vec = ft_fill(atoi(ax[0]), atoi(ax[1]), atoi(ax[2]));
	ft_delarr(ax, ind);
	return (vec);
}
