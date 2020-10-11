/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:42:42 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 06:44:17 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		f_len;
	size_t		s_len;
	char		*str_j;

	if (!s1 || !s2)
		return (NULL);
	f_len = ft_strlen(s1);
	s_len = ft_strlen(s2);
	str_j = ft_calloc(f_len + s_len + 1, sizeof(char));
	if (str_j == NULL)
		return (NULL);
	ft_strlcat(str_j, s1, f_len + s_len + 1);
	ft_strlcat(str_j, s2, f_len + s_len + 1);
	return (str_j);
}
