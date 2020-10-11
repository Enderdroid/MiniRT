/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:31:27 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 09:55:01 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

# include "libincludes.h"

int		rt_validate(char **argv);
int		ft_message(char *msg, int ret);
void	ft_exit(char *str);
void	my_put_image_to_window(t_vars *vars, t_data *img, int ind);
void	my_mpp(t_data *data, int x, int y, int color);
char	**ft_split(char const *s, char c, int *size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
double	ft_atof(const char *str);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isdigit(int c);
int		get_sign(float f);
void	*ft_memset(void *destination, int c, size_t n);
void	ft_delarr(char **arr, int size);
int		**crt_mtx(int x, int y);
int		num_val(char *num, const char type);
int		val_order(char **arr, char *str);
int		put_err(int err_code, char *data, int ret);
int		put_row(int row);
void	*ft_calloc(size_t num, size_t size);
int		free_data(t_vars *vars, t_scene *scene);
void	fill_arr(int *dst, int val, int size);

#endif
