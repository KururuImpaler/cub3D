/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

double	start_x(double *x, double *y, t_cub *cub)
{
	double	step;

	step = 1.0;
	if (cub->alpha < 180)
		*x = *x + cub->step_map;
	else
	{
		*x = *x - 0.001;
		step = -1.0;
	}
	*y = cub->pos_y + (cub->pos_x - *x) / (cub->t_view * (-1));
	return (step);
}

double	start_y(double *x, double *y, t_cub *cub)
{
	double	step;

	step = 1.0;
	if (cub->alpha < 90 || cub->alpha > 270)
		*y = *y + cub->step_map;
	else
	{
		*y = *y - 0.001;
		step = -1.0;
	}
	*x = cub->pos_x + (cub->pos_y - *y) * cub->t_view * (-1);
	return (step);
}

int		ft_small(double z1, double z2, double pos_z)
{
	return ((fabs(pos_z - z2) < fabs(pos_z - z1)) ? 1 : 0);
}

int		ft_raycast_y(double *x, double *y, t_cub *cub, double step)
{
	int		hit;

	hit = 0;
	if (check_hit(*x, *y, cub, 1) == 0)
	{
		if (cub->alpha > 90 && cub->alpha < 270)
			cub->num_wall = 2;
		else
			cub->num_wall = 1;
		hit = 1;
	}
	*y += cub->step_map * step;
	*x += cub->step_map * cub->t_view * step;
	return (hit);
}

int		ft_raycast_x(double *x, double *y, t_cub *cub, double step)
{
	int		hit;

	hit = 0;
	if (check_hit(*x, *y, cub, 1) == 0)
	{
		if (cub->alpha > 180)
			cub->num_wall = 0;
		else
			cub->num_wall = 3;
		hit = 1;
	}
	*x += cub->step_map * step;
	*y += cub->step_map / (cub->t_view * step);
	return (hit);
}
