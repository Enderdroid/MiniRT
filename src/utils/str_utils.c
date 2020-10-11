/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:49:39 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:49:39 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int					ft_atoi(const char *str)
{
	long long int	num;
	unsigned char	*s;
	int				i;

	num = 1;
	i = 0;
	s = (unsigned char *)str;
	if (s[i] >= '0' && s[i] <= '9')
		num *= (long long int)(s[i] - '0');
	else
		return (-1);
	while (s[++i] >= '0' && s[i] <= '9')
		num = num * 10 + (long long int)(s[i] - '0');
	return ((int)(num));
}

double				ft_atof(const char *str)
{
	int				i_val;
	int				sign;
	double			val;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	i_val = ft_atoi(str);
	while (ft_isdigit(*str))
		++str;
	if (!(*str) && i_val >= 0)
		return (i_val * sign);
	val = (double)ft_atoi(++str);
	while (val >= 1)
		val /= 10;
	while (*(str++) == '0')
		val /= 10;
	val += (double)i_val;
	return (val * sign);
}

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int					ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	i = 0;
	us1 = (unsigned char *)str1;
	us2 = (unsigned char *)str2;
	while (us1[i] == us2[i] && us1[i] && us2[i])
		++i;
	return (us1[i] - us2[i]);
}

void				ft_delarr(char **arr, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}
