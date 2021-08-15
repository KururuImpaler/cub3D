/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_zero_2(t_cub *cub)
{
	cub->column = 0;
	cub->delta = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->map_size_x = 0;
	cub->map_size_y = 0;
	cub->start = 0;
	cub->sl = 0;
	cub->e = 0;
	cub->img = 0;
	cub->data_img = 0;
	cub->i_bpp = 0;
	cub->width = 0;
	cub->height = 0;
	cub->len = 0;
	cub->dist = 0;
	cub->speed = 4.5;
	cub->speed_alpha = 2.5;
	cub->sprites.x = 0;
	cub->sprites.height = 0;
	cub->sprites.num = 0;
	cub->sprites.all_s = 0;
	cub->data_map = 0;
	cub->m_map = -1;
	cub->error = 4;
}

void	ft_zero_1(t_cub *cub)
{
	cub->mlx = 0;
	cub->win = 0;
	cub->map = 0;
	cub->key_a = 0;
	cub->key_d = 0;
	cub->key_s = 0;
	cub->key_w = 0;
	cub->key_left = 0;
	cub->key_right = 0;
	cub->alpha = 0;
	cub->beta = 0;
	cub->dir_angle = 0;
	cub->pdx = 0;
	cub->pdy = 0;
	cub->pdx2 = 0;
	cub->pdy2 = 0;
	cub->pos_x = 0;
	cub->pos_y = 0;
	cub->step_map = 64;
	cub->t_view = 0;
	cub->num_wall = 0;
	cub->minimap = 0;
	cub->check = 0;
	ft_zero_2(cub);
}

int		ft_zero(t_cub *cub)
{
	int		i;

	ft_zero_1(cub);
	i = -1;
	while (++i < 8)
	{
		if (i < 3)
			cub->f_col[i] = -1;
		if (i < 3)
			cub->c_col[i] = -1;
		if (i < 5)
			cub->bpp[i] = 0;
		if (i < 5)
			cub->bpp[i] = 0;
		if (i < 5)
			cub->t_h[i] = 0;
		if (i < 5)
			cub->t_w[i] = 0;
		if (i < 5)
			cub->tex[i] = 0;
		if (i < 5)
			cub->data_t[i] = 0;
		cub->map_var[i] = 0;
	}
	return (0);
}
