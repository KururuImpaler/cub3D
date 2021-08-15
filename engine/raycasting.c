/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_sprite_height(t_cub *cub, double x, double y)
{
	int		height;

	x = pow((cub->pos_x - x), 2.0);
	y = pow((cub->pos_y - y), 2.0);
	height = (int)ceil(sqrt(x + y));
	return (height);
}

void	sprites_data(t_cub *cub, double x1, double y1, int z)
{
	int		n;
	double	x2;
	double	y2;
	double	x;

	n = cub->sprites.num;
	cub->sprites.num += 1;
	x2 = floor(x1 / cub->step_map) * cub->step_map + cub->step_map / 2;
	y2 = floor(y1 / cub->step_map) * cub->step_map + cub->step_map / 2;
	cub->sprites.height[n] = ft_sprite_height(cub, x2, y2);
	x = ft_sprite_angle(cub, cub->pos_x - x2, cub->pos_y - y2, n);
	y2 = (double)cub->sprites.height[n] / (double)cub->t_h[4];
	x2 = (double)cub->t_w[4] * y2;
	x = (double)(z + (int)x - (int)x2 / 2);
	x = (double)(z - (int)x);
	x = x / y2;
	cub->sprites.x[n] = (int)x;
}

int		check_hit(double x, double y, t_cub *cub, int hit)
{
	double	x1;
	double	y1;
	int		i;
	int		j;

	i = (int)(y / cub->step_map);
	j = (int)(x / cub->step_map);
	i = ft_map_pos(i, (int)(cub->map_size_y / cub->step_map));
	j = ft_map_pos(j, (int)(cub->map_size_x / cub->step_map));
	if (cub->map[i][j] == '1' || cub->map[i][j] == ' ')
		hit = 0;
	if (cub->map[i][j] == '2')
		sprites_data(cub, x, y, cub->column);
	cub->map_x = x - floor(x / cub->step_map) * cub->step_map;
	cub->map_y = y - floor(y / cub->step_map) * cub->step_map;
	x1 = cub->pos_x - x;
	y1 = cub->pos_y - y;
	if (hit == 0)
	{
		cub->h_wall = sqrt(pow((x1), 2.0) + pow((y1), 2.0)) * ft_cos(cub->beta);
		cub->h_wall = (int)ceil(cub->dist / cub->h_wall);
	}
	return (hit);
}

void	raycast_next(double x1, double y2, t_cub *cub)
{
	double	x2;
	double	y1;
	double	step_x;
	double	step_y;

	step_x = start_x(&x1, &y1, cub);
	step_y = start_y(&x2, &y2, cub);
	while (42)
	{
		if (ft_small(x1, x2, cub->pos_x) && ft_small(y1, y2, cub->pos_y))
		{
			if (ft_raycast_y(&x2, &y2, cub, step_y))
				break ;
		}
		else
		{
			if (ft_raycast_x(&x1, &y1, cub, step_x))
				break ;
		}
	}
}

void	ft_raycast(t_cub *cub, int z, int check)
{
	double	x;
	double	y;

	cub->column = z;
	x = floor(cub->pos_x / cub->step_map) * cub->step_map;
	y = floor(cub->pos_y / cub->step_map) * cub->step_map;
	cub->t_view = ft_tan(cub->alpha);
	if (cub->t_view == 0.0)
		cub->t_view += 0.1;
	cub->sprites.num = 0;
	raycast_next(x, y, cub);
	if (check == 1)
	{
		check = 0;
		cub->alpha += cub->delta * 2;
		cub->beta += cub->delta * 2;
	}
	if (check == 2)
	{
		check = 0;
		cub->alpha -= cub->delta;
		cub->beta -= cub->delta;
	}
	cub->alpha -= cub->delta;
	cub->beta -= cub->delta;
}
