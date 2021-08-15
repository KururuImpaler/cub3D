/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_draw_ceiling(t_cub *cub, int j, int i)
{
	int		max;

	i = -1;
	if (i + cub->h_wall > cub->height)
		return ;
	max = cub->height / 2 - (int)cub->h_wall / 2;
	while (++i < max)
		cub->data_img[i][j] = cub->c_c;
}

void	ft_draw_wall(t_cub *cub, int i, int j, int n)
{
	int		x;
	double	y;
	int		max;
	double	delta;

	y = 0;
	i = cub->height / 2 - cub->h_wall / 2 - 1;
	delta = ft_delta_wall(cub, &i, &max, &y);
	if (n == 1 || n == 2)
		x = (int)(cub->map_x / (cub->step_map / (double)cub->t_w[n]));
	else
		x = (int)(cub->map_y / (cub->step_map / (double)cub->t_w[n]));
	while (++i < max && y < cub->t_h[n])
	{
		cub->data_img[i][j] = cub->data_t[n][(int)floor(y)][x];
		y += delta;
		if (y >= (double)cub->t_h[n])
			y = (double)(cub->t_h[n] - 1);
	}
}

void	ft_draw_floor(t_cub *cub, int i, int j)
{
	int		max;

	i = cub->height / 2 - cub->h_wall / 2 - 1;
	i += cub->h_wall - 1;
	max = cub->height;
	while (++i < max)
		cub->data_img[i][j] = cub->f_c;
}

void	ft_draw_sprites(t_cub *cub, int j, int i, int n)
{
	int		x;
	double	y;
	int		max;
	double	delta;

	x = cub->sprites.x[n];
	y = 0;
	cub->sprites.num = n;
	delta = ft_delta_sprites(cub, &i, &max, &y);
	while (++i < max)
	{
		if (ft_none_color(cub->data_t[4], (int)y, x))
			cub->data_img[i][j] = cub->data_t[4][(int)floor(y)][x];
		y += delta;
	}
}

int		ft_draw(t_cub *cub, int x)
{
	int		i;
	int		z;

	i = 0;
	ft_draw_ceiling(cub, x, i);
	ft_draw_wall(cub, i, x, cub->num_wall);
	ft_draw_floor(cub, i, x);
	i = cub->sprites.num;
	while (i-- > 0)
	{
		z = cub->sprites.x[i];
		if (z >= 0 && z < cub->t_w[4])
			ft_draw_sprites(cub, x, 0, i);
	}
	return (ft_artifacts(cub));
}
