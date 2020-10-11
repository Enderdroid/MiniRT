/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:46:39 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:52:55 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"
#include "libvectors.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	str_validate(char *str, int *ar_c)
{
	char	**arr;
	int		buf;
	int		id;

	if (str[ft_strlen(str) - 1] == 13)
		str[ft_strlen(str) - 1] = 0;
	buf = -1;
	while (str[++buf])
		if ((str[buf] == ' ' || str[buf] == '\t') && (id = str[buf]))
			break ;
	arr = ft_split(str, id, &buf);
	if (!arr || ((id = ft_stoc(arr[0])) < 0 || id > 8))
	{
		if (!arr)
			return (put_err(3, "split->ft_strValidate", -1));
		ft_delarr(arr, buf);
		return (put_err(2, "bad id", -1));
	}
	if (id == 7 || id == 8)
		++(ar_c[id - 7]);
	id = id_check(arr, id, buf);
	ft_delarr(arr, buf);
	return (id);
}

int			rt_validate(char **argv)
{
	int		fd;
	int		ret;
	int		v_ret[2];
	char	*str;
	int		ar_c[2];

	fill_arr(ar_c, 0, 2);
	fill_arr(v_ret, 0, 2);
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)) >= 0 && ++v_ret[1])
	{
		if (*str && str[0] != '#' && str[0] != 13 && str[0] != 10)
			v_ret[0] = str_validate(str, ar_c);
		free(str);
		if (ret == 0 || v_ret[0] < 0)
			break ;
	}
	if (ret < 0)
		return (put_err(1, "GNL fault", -1));
	else if (v_ret[0] < 0)
		return (put_row(v_ret[1]));
	else if (ar_c[0] != 1 || ar_c[1] != 1)
		return (put_err(1, "bad capital obj count", -1));
	return (0);
}
