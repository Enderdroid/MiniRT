/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 06:15:36 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:50:28 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminirt.h"

t_color			fill_color(int r, int g, int b, int a)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

int				ft_stoint(t_color color)
{
	return (0 << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_color			ft_inttos(int color)
{
	t_color		new;

	new.a = 0;
	new.b = color & 0xFF;
	new.g = (color & (0xFF << 8)) / 256;
	new.r = (color & (0xFF << 16)) / (256 * 256);
	return (new);
}

int				make_shad(int basic, t_vec3 mult)
{
	t_color		new;

	new = ft_inttos(basic);
	new.a = 0;
	new.r = (int)(new.r * mult.x);
	new.g = (int)(new.g * mult.y);
	new.b = (int)(new.b * mult.z);
	return (ft_stoint(new));
}

t_color			vec_to_color(t_vec3 vec)
{
	t_color		color;

	color.a = 0;
	color.r = vec.x;
	color.g = vec.y;
	color.b = vec.z;
	return (color);
}
