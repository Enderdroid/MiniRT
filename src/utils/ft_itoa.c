/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:39:48 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 06:41:08 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static size_t		ft_getlen(long num)
{
	size_t			len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char			*str;
	long long int	num;
	size_t			i;

	num = (long long int)n;
	i = ft_getlen(num);
	if (!(str = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	str[i] = '\0';
	str[0] = '0';
	if (num == 0)
		return (str);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[--i] = '0' + (char)(num % 10);
		num /= 10;
	}
	return (str);
}
