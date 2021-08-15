/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_window(t_cub *cub)
{
	int		x;
	int		check;
	int		y;

	x = -1;
	check = 0;
	if (cub->m_map > 0)
		minimap_draw(cub, 0, 0);
	while (++x < cub->width)
	{
		ft_angle(cub);
		ft_raycast(cub, x, check);
		check = ft_draw(cub, x);
	}
	cub->alpha += 30;
	ft_angle(cub);
	x = cub->width / 6 * 5 - 5;
	y = cub->height / 6 * 5 - 5;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	if (cub->m_map > 0)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap, x, y);
	mlx_do_sync(cub->mlx);
}

int		ft_position(t_cub *cub)
{
	if (cub->key_left)
		cub->alpha += 1 * cub->speed_alpha;
	if (cub->key_right)
		cub->alpha -= 1 * cub->speed_alpha;
	ft_angle(cub);
	ft_move(cub);
	if (cub->key_d)
		ft_move_left_right(cub, 1.0);
	if (cub->key_a)
		ft_move_left_right(cub, -1.0);
	if (cub->key_w)
		ft_move_forward_back(cub, 1.0);
	if (cub->key_s)
		ft_move_forward_back(cub, -1.0);
	cub->dir_angle = cub->alpha;
	cub->alpha += 30;
	cub->beta = 30;
	ft_window(cub);
	return (0);
}
