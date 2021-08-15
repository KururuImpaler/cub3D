/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_exit(t_cub *cub, int n)
{
	mlx_destroy_window(cub->mlx, cub->win);
	ft_free(cub, n);
	return (0);
}

int		ft_exit_2(t_cub *cub)
{
	ft_free(cub, 0);
	return (0);
}

void	ft_error(int n, t_cub *cub)
{
	write(2, "Error\n", 6);
	if (n == 1)
	{
		if (cub->error == 1)
			write(2, "Could not read the file.\n", 25);
		else if (cub->error == 2)
			write(2, "Failed to allocate memory.\n", 27);
		else if (cub->error == 3)
			write(2, "Failed to create image.\n", 24);
		else if (cub->error == 4)
			write(2, "Map file not valied!\n", 21);
	}
	else if (n == 2)
		write(2, "Failed to establish connection\n", 31);
	else if (n == 3)
		write(2, "Failed to create window\n", 24);
	else if (n == 4)
		write(2, "Failed to create screen!\n", 25);
}

void	ft_free_2(t_cub *cub)
{
	if (cub->img != 0)
		mlx_destroy_image(cub->mlx, cub->img);
	if (cub->data_img != 0)
		free(cub->data_img);
	if (cub->map != 0)
		free(cub->map);
	if (cub->sprites.height != 0)
		free(cub->sprites.height);
	if (cub->sprites.x != 0)
		free(cub->sprites.x);
	if (cub->minimap != 0)
		mlx_destroy_image(cub->mlx, cub->minimap);
	if (cub->data_map != 0)
		free(cub->data_map);
	if (cub->mlx != 0)
		free(cub->mlx);
}

void	ft_free(t_cub *cub, int n)
{
	if (n > 0)
		ft_error(n, cub);
	n = -1;
	while (++n < 5)
	{
		if (cub->tex[n] != 0)
			mlx_destroy_image(cub->mlx, cub->tex[n]);
		if (cub->data_t[n] != 0)
			free(cub->data_t[n]);
	}
	n = -1;
	while (cub->map != 0 && ++n < (int)(cub->map_size_y / cub->step_map))
		if (cub->map[n] != 0)
			free(cub->map[n]);
	ft_free_2(cub);
	exit(ft_zero(cub));
}
