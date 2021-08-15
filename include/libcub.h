/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "libmap.h"

int				ft_all(t_cub *cub);
int				ft_keys_down(int key, t_cub *cub);
int				ft_keys_up(int key, t_cub *cub);
int				ft_position(t_cub *cub);
int				ft_exit(t_cub *cub, int n);
int				ft_exit_2(t_cub *cub);
void			ft_free(t_cub *cub, int n);
int				ft_map_valied(char *name, t_cub *cub, int fd, int n);
int				ft_position_s(t_cub *cub);
int				ft_zero(t_cub *cub);

void			ft_angle(t_cub *cub);
double			ft_sin(double angle);
double			ft_cos(double angle);
double			ft_tan(double angle);
double			ft_atan(double angle);

void			ft_raycast(t_cub *cub, int z, int check);
int				ft_raycast_x(double *x, double *y, t_cub *cub, double step);
int				ft_raycast_y(double *x, double *y, t_cub *cub, double step);
int				ft_small(double z1, double z2, double pos_z);
double			start_y(double *x, double *y, t_cub *cub);
double			start_x(double *x, double *y, t_cub *cub);
int				check_hit(double x, double y, t_cub *cub, int hit);
int				ft_map_pos(int i, int z);
double			ft_sprite_angle(t_cub *cub, double x, double y, int n);

int				ft_draw(t_cub *cub, int x);
int				ft_none_color(t_ui **data, int i, int j);
int				ft_artifacts(t_cub *cub);
double			ft_delta_sprites(t_cub *cub, int *i, int *max, double *y);
double			ft_delta_wall(t_cub *cub, int *i, int *max, double *y);
int				get_color_pixel(char *data, int color);

void			ft_move_left_right(t_cub *cub, double n);
void			ft_move_forward_back(t_cub *cub, double n);
void			ft_move(t_cub *cub);

void			minimap_draw(t_cub *cub, int x, int y);
#endif
