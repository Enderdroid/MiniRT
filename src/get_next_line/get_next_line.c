/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:40:39 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 05:43:24 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strset(char *dest, char const *src, int val, int size)
{
	int			i;

	i = 0;
	if (!size)
		return (0);
	if (src)
	{
		while (i < size)
		{
			dest[i] = src[i];
			++i;
		}
	}
	else
	{
		while (i < size)
		{
			dest[i] = val;
			++i;
		}
	}
	return (1);
}

static int		ft_proc(char *buf, char *s, char **line, int ret)
{
	size_t		i;
	size_t		j;

	j = 0;
	ft_strset(s, NULL, 0, BUFFER_SIZE + 1);
	if (ret < 0)
		*line = g_strjoin(NULL, buf);
	else
		*line = g_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	i = g_strlen(buf);
	if (!(buf[i]) && (i == BUFFER_SIZE || ret == -2))
		return (2);
	else if (!(buf[i]))
		return (0);
	else
		while (buf[++i])
			s[j++] = buf[i];
	ft_strset(buf, NULL, 0, BUFFER_SIZE + 1);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	s[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	int			siz;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ret = -1;
	if (s[0] != 0 && ft_strset(buf, s, 0, BUFFER_SIZE))
		if ((ret = ft_proc(buf, s, line, -2)) == 1 || ret == -1)
			return (ret);
	while ((siz = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[siz] = 0;
		if (!(ret = ft_proc(buf, s, line, ret)) || ret == 1 || ret == -1)
			return (ret);
	}
	if (siz < 0)
		return (-1);
	if (ret == 2)
		get_next_line(fd, line);
	if (ret == -1 && *s)
		*line = g_strjoin(NULL, s);
	return (0);
}
