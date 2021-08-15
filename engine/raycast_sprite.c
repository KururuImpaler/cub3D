/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

double	ft_sprite_angle_2(t_cub *cub, double angle, double x)
{
	if (cub->dir_angle >= 0 && cub->dir_angle < 90 && x < 0)
		angle = 90 - angle;
	else if (cub->dir_angle >= 0 && cub->dir_angle < 90 && x > 0)
		angle = (90 + angle) * -1;
	if (cub->dir_angle >= 90 && cub->dir_angle < 180 && x < 0)
		angle = 90 - angle;
	else if (cub->dir_angle >= 90 && cub->dir_angle < 180 && x > 0)
		angle = 270 - angle;
	if (cub->dir_angle >= 180 && cub->dir_angle < 270 && x > 0)
		angle = 270 - angle;
	else if (cub->dir_angle >= 180 && cub->dir_angle < 270 && x < 0)
		angle = 90 - angle;
	if (cub->dir_angle >= 270 && cub->dir_angle < 360 && x > 0)
		angle = 270 - angle;
	else if (cub->dir_angle >= 270 && cub->dir_angle < 360 && x < 0)
		angle = 360 + (90 - angle);
	return (angle);
}

double	ft_sprite_angle(t_cub *cub, double x, double y, int n)
{
	double	angle;
	double	alpha;

	if (x == 0)
		x += 0.01;
	if (y == 0)
		y += 0.01;
	angle = ft_atan(y / x);
	alpha = cub->alpha;
	if (cub->dir_angle > 270 && alpha < 90)
		alpha = 360 + alpha;
	if (cub->dir_angle < 90 && alpha > 270)
		alpha = (360 - alpha) * -1;
	angle = alpha - ft_sprite_angle_2(cub, angle, x);
	x = cub->beta - angle;
	x = (double)cub->sprites.height[n] * ft_cos(x);
	cub->sprites.height[n] = (int)ceil(cub->dist / x);
	return (angle / cub->delta);
}

int		ft_map_pos(int i, int z)
{
	if (i < 0)
		i = 0;
	if (i >= z)
		i = z - 1;
	return (i);
}
