/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_move(t_cub *cub)
{
	double	angle;

	angle = cub->alpha - 90;
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	cub->pdx = ft_sin(cub->alpha) * cub->speed;
	cub->pdy = ft_cos(cub->alpha) * cub->speed;
	cub->pdx2 = ft_sin(angle) * cub->speed;
	cub->pdy2 = ft_cos(angle) * cub->speed;
}

int		ft_stop_move(t_cub *cub, double n, double pdz, int m)
{
	int		x;
	int		y;

	x = (int)(cub->pos_x / cub->step_map);
	y = (int)(cub->pos_y / cub->step_map);
	if (m == 1)
		x = (int)((cub->pos_x + pdz * 4 * n) / cub->step_map);
	if (m == 2)
		y = (int)((cub->pos_y + pdz * 4 * n) / cub->step_map);
	if (cub->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_move_forward_back(t_cub *cub, double n)
{
	if (ft_stop_move(cub, n, cub->pdx, 1) == 0)
		cub->pos_x += cub->pdx * n;
	if (ft_stop_move(cub, n, cub->pdy, 2) == 0)
		cub->pos_y += cub->pdy * n;
}

void	ft_move_left_right(t_cub *cub, double n)
{
	if (ft_stop_move(cub, n, cub->pdx2, 1) == 0)
		cub->pos_x += cub->pdx2 * n;
	if (ft_stop_move(cub, n, cub->pdy2, 2) == 0)
		cub->pos_y += cub->pdy2 * n;
}
