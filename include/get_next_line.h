/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:30:57 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:54:30 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*g_strjoin(char *s1, char const *s2);
size_t		g_strlen(const char *s);

#endif
