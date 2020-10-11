/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:05:45 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:55:10 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTORS_H
# define LIBVECTORS_H

# include "libincludes.h"

float	ft_mint(float *t, int size);
float	ft_dot(t_vec3 u, t_vec3 v);
float	sqrdot(t_vec3 u);
t_vec3	ft_cross(t_vec3 u, t_vec3 v);
t_vec3	ft_fill(float x, float y, float z);
t_vec3	ft_inv(t_vec3 v);
t_vec3	ft_minus(t_vec3 u, t_vec3 v);
t_vec3	ft_mult(t_vec3 u, float val);
t_vec3	ft_plus(t_vec3 u, t_vec3 v);
float	ft_dist(t_vec3 v, t_vec3 u);
t_vec3	ft_norm(t_vec3 u, t_vec3 v);
t_vec3	vec_parse(char *str, const char type);
int		ft_stoc(char *str);
char	*ft_ctos(int id);
int		id_check(char **arr, char id, int buf);
void	sqr_vert_init(t_vec3 *v, t_vec3 nix, t_vec3 niy, t_vec3 o);
t_vec3	get_axis(t_vec3 dest, t_vec3 pln, float len);

#endif
