/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_angle(t_cub *cub)
{
	if (cub->alpha >= 360.0)
		cub->alpha -= 360.0;
	else if (cub->alpha < 0.0)
		cub->alpha += 360.0;
	else if (cub->beta >= 360.0)
		cub->beta -= 360.0;
	else if (cub->beta < 0.0)
		cub->beta += 360.0;
	else if (cub->dir_angle >= 360.0)
		cub->dir_angle -= 360.0;
	else if (cub->dir_angle < 0.0)
		cub->dir_angle += 360.0;
}

double	ft_sin(double angle)
{
	return (sin(angle * PI));
}

double	ft_cos(double angle)
{
	return (cos(angle * PI));
}

double	ft_tan(double angle)
{
	return (tan(angle * PI));
}

double	ft_atan(double angle)
{
	return (atan(angle) / PI);
}
