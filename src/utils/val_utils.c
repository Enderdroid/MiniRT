/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:47:13 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/12 01:20:15 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"
#include "libvectors.h"

static int	vec_val(char *vec, const char type)
{
	int		ind;
	int		size;
	char	**num;

	size = 0;
	num = ft_split(vec, ',', &size);
	if (size != 3)
		return (-1);
	ind = num_val(num[0], type);
	if (ind < 0 || num[0][ind] != '\0')
		return (-1);
	ind = num_val(num[1], type);
	if (ind < 0 || num[1][ind] != '\0')
		return (-1);
	ind = num_val(num[2], type);
	if (ind < 0 || num[2][ind] != '\0')
		return (-1);
	ft_delarr(num, size);
	return (1);
}

int			num_val(char *num, const char type)
{
	int		ind;

	ind = 0;
	if (*num == '-' || *num == '+')
		++ind;
	if (!ft_isdigit(num[ind]))
		return (-1);
	while (ft_isdigit(num[ind]))
		++ind;
	if (num[ind] == '\0' || num[ind] == ',' || type == 'I' || type == 'i')
		return (ind);
	if (num[ind] != '.' || (num[ind] == '.' && !ft_isdigit(num[ind + 1])))
		return (-1);
	++ind;
	while (ft_isdigit(num[ind]))
		++ind;
	if (num[ind] != '\0' || (type != 'F' && type != 'f' && type != 'N'))
		return (-1);
	return (ind);
}

int			val_order(char **arr, char *str)
{
	int		ind;

	ind = 0;
	while (str[ind])
	{
		if (str[ind] == 'i' || str[ind] == 'f')
		{
			if (num_val(arr[ind + 1], str[ind]) < 0)
				return (put_err(2, "numb def", -1));
		}
		else if (str[ind] == 'I' || str[ind] == 'F')
		{
			if (vec_val(arr[ind + 1], str[ind]) < 0)
				return (put_err(2, "vec def", -1));
		}
		else if (vec_val(arr[ind + 1], str[ind]) < 0)
			return (put_err(2, "normal vec def", -1));
		// else if (sqrdot(vec_parse(arr[ind + 1], 'F')) != 1)
			// return (put_err(2, "vector is not normalized", -1));
		++ind;
	}
	return (0);
}

void		fill_arr(int *dst, int val, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		dst[i] = val;
		++i;
	}
}
