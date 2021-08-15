/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

double	ft_delta_wall(t_cub *cub, int *i, int *max, double *y)
{
	double	delta;
	int		n;

	n = cub->num_wall;
	delta = ((double)cub->t_h[n] / (double)cub->h_wall);
	if (*i + cub->h_wall > cub->height)
		*max = cub->height;
	else
		*max = *i + cub->h_wall;
	if (*i < -1)
	{
		*y += delta * (double)*i * -1.0;
		*i = -1;
	}
	return (delta);
}

double	ft_delta_sprites(t_cub *cub, int *i, int *max, double *y)
{
	double	delta;
	int		n;
	double	del;

	del = 2.3;
	n = cub->sprites.num;
	delta = (double)cub->t_h[4] / (double)cub->sprites.height[n];
	*i = cub->height / 2 - (int)((double)cub->sprites.height[n] / del) - 1;
	if (*i + cub->sprites.height[n] > cub->height)
		*max = cub->height;
	else
		*max = *i + cub->sprites.height[n];
	if (*i < -1)
	{
		*y += delta * (double)*i * -1.0;
		*i = -1;
	}
	return (delta);
}

t_ui	ft_color(int red, int green, int blue)
{
	t_ui	color;

	color = (t_ui)red << 16;
	color += (t_ui)green << 8;
	color += (t_ui)blue;
	return (color);
}

int		ft_none_color(t_ui **data, int i, int j)
{
	if (data[i][j] == 0)
		return (0);
	return (1);
}

int		ft_artifacts(t_cub *cub)
{
	if (floor(cub->alpha) == 180.0)
	{
		cub->alpha -= cub->delta * 2;
		cub->beta -= cub->delta * 2;
		return (1);
	}
	if (floor(cub->alpha) == 0.0)
	{
		cub->alpha += cub->delta;
		cub->beta += cub->delta;
		return (2);
	}
	return (0);
}
