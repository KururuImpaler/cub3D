/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	player_draw(t_cub *cub, double px, double py)
{
	int		i;
	int		j;
	int		k;
	int		l;

	j = (int)floor(cub->pos_x / px) - 2;
	i = (int)floor(cub->pos_y / py) - 2;
	k = -1;
	while (++k < 5)
	{
		l = -1;
		while (++l < 5)
			cub->data_map[(i + k)][(j + l)] = ft_color(120, 0, 120);
	}
}

int		ft_resize_map(t_cub *cub, double *x, double *y)
{
	double	px;
	double	py;

	px = (double)(cub->width / 6);
	px = cub->map_size_x / px;
	py = (double)(cub->height / 6);
	py = cub->map_size_y / py;
	*x = px;
	*y = py;
	return (-1);
}

void	minimap_draw(t_cub *cub, int x, int y)
{
	int		i;
	int		j;
	double	px;
	double	py;

	i = ft_resize_map(cub, &px, &py);
	while (++i < cub->height / 6)
	{
		j = -1;
		while (++j < cub->width / 6)
		{
			y = (int)floor(((double)i * py) / cub->step_map);
			x = (int)floor(((double)j * px) / cub->step_map);
			cub->data_map[i][j] = ft_color(0, 0, 0);
			if (cub->map[y][x] == '1')
				cub->data_map[i][j] = ft_color(120, 0, 0);
			if (cub->map[y][x] == '0' || ft_memchr("NWES", cub->map[y][x], 4))
				cub->data_map[i][j] = ft_color(0, 120, 0);
			if (cub->map[y][x] == '2')
				cub->data_map[i][j] = ft_color(0, 0, 120);
		}
	}
	player_draw(cub, px, py);
}
