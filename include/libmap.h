/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAP_H
# define LIBMAP_H

# include "cubdata.h"
#include <stdio.h>

int		get_line_map(int fd, char **line, int n, t_cub *cub);
int		ft_true_false(int *c, t_cub *cub);
int		ft_parser(char *line, int n, int i, t_cub *cub);
int		ft_map_parse(int fd1, char *line, char *name, t_cub *cub);
int		ft_data_map(t_cub *cub);
int		map_valied(t_cub *cub, char *line, int fd);
int		ft_pass_char(char *s, int i, char c);
int		ft_check_str(char *s, t_cub *cub);
int		string_if_2(int *i, char c1, char c2);
int		ft_close(int fd, int i);
int		ft_check_2(int *var, int i);
int		ft_valied_2(char *s);
int		ft_valied_1(char *s1, char *s2, int *i);
int		ft_valied(char *s1, char *s2, int i);
void	ft_wall_string(char *s, char *s1, int i);
int		ft_size_map(t_cub *cub, int fd, int w, int h);
int		map_size_line_2(int n, int p, int l1, int l2);
int		ft_minimap_image(t_cub *cub, char *data, int n);
int		ft_error_map(t_cub *cub, int error, int ret);
char	*ft_error_map2(t_cub *cub, int error, char *ret);
t_ui	ft_color(int red, int green, int blue);
int		ft_atoi_map(char *s, int *i);

#endif
