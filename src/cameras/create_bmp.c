/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:17:25 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:53:39 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

static size_t		bmp_fsize(t_res *res)
{
	size_t			resolution;

	resolution = 14;
	resolution += 40;
	resolution += 4 * res->width * res->height;
	return (resolution);
}

static void			bmp_wr_header(char *buf, size_t fsize, t_res *res)
{
	*((uint16_t *)&buf[0x00]) = (uint16_t)0x4d42;
	*((uint32_t *)&buf[0x02]) = (uint32_t)fsize;
	*((uint32_t *)&buf[0x0A]) = (uint32_t)0x0E + 40;
	*((uint32_t *)&buf[0x0E]) = (uint32_t)40;
	*((uint32_t *)&buf[0x12]) = (uint32_t)res->width;
	*((uint32_t *)&buf[0x16]) = (uint32_t)res->height;
	*((uint16_t *)&buf[0x1A]) = (uint16_t)1;
	*((uint16_t *)&buf[0x1C]) = (uint16_t)32;
}

static void			bmp_wr_pixels(char *buf, int **img, t_res *res)
{
	uint32_t		index;
	int				x;
	int				y;
	t_color			col;

	index = 0x0E + 40;
	y = res->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < res->width)
		{
			col = ft_inttos(img[x][y]);
			buf[index + 0] = col.b;
			buf[index + 1] = col.g;
			buf[index + 2] = col.r;
			buf[index + 3] = 0;
			index += 4;
		}
	}
	x = -1;
	while (++x < res->width)
		free(img[x]);
	free(img);
}

static char			*get_name(char *scene_name, int ind)
{
	char			*num;
	char			*file_name;
	unsigned int	len;

	num = ft_itoa(ind);
	len = ft_strlen(scene_name) + ft_strlen(num) + 6;
	file_name = ft_calloc(len, sizeof(char));
	if (!file_name)
		return (NULL);
	ft_strlcat(file_name, scene_name, ft_strlen(scene_name) - 2);
	ft_strlcat(file_name, "_", len);
	ft_strlcat(file_name, num, len);
	free(num);
	ft_strlcat(file_name, ".bmp", len);
	return (file_name);
}

int					save_bmp(t_res *res, int **img, char *scene_name, int ind)
{
	char			*buf;
	char			*file_name;
	int				fd;
	size_t			fsize;

	if (!(file_name = get_name(scene_name, ind)))
		return (put_err(3, "save_bmp->get_name", -1));
	fd = open(file_name, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return (put_err(5, "in save_bmp", -1));
	fsize = bmp_fsize(res);
	buf = malloc(fsize);
	if (!buf)
		return (put_err(3, "save_bmp", -1));
	ft_memset(buf, 0, fsize);
	bmp_wr_header(buf, fsize, res);
	bmp_wr_pixels(buf, img, res);
	if (write(fd, buf, fsize) < 0)
		return (put_err(6, "Writing failed", -1));
	if (close(fd) < 0)
		return (put_err(6, "Closing failed", -1));
	free(buf);
	free(file_name);
	return (0);
}
