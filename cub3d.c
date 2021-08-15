/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libcub.h"

int		ft_cub(char *arg)
{
	int		error;
	t_cub	cub;

	ft_zero(&cub);
	cub.mlx = mlx_init();
	if (cub.mlx == 0)
		ft_free(&cub, 2);
	error = ft_map_valied(arg, &cub, 0, 0);
	if (error == 0)
		ft_free(&cub, 1);
	cub.win = mlx_new_window(cub.mlx, cub.width, cub.height, "Cub3D");
	if (cub.win == 0)
		ft_free(&cub, 3);
	mlx_hook(cub.win, 17, (1L << 17), &ft_exit_2, &cub);
	mlx_hook(cub.win, 2, (1L << 0), &ft_keys_down, &cub);
	mlx_hook(cub.win, 3, (1L << 1), &ft_keys_up, &cub);
	mlx_loop_hook(cub.mlx, &ft_all, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

int		ft_screen(char *arg)
{
	int		error;
	t_cub	cub;

	ft_zero(&cub);
	cub.mlx = mlx_init();
	if (cub.mlx == 0)
		ft_free(&cub, 2);
	error = ft_map_valied(arg, &cub, 0, 0);
	if (error == 0)
		ft_free(&cub, 1);
	ft_position_s(&cub);
	return (0);
}

int		ft_screen_name(char *name)
{
	if (ft_memcmp("--save\0", name, 7) == 0)
		return (1);
	return (0);
}

int		ft_map_name(char *name)
{
	int		i;

	i = ft_strlen(name) - 4;
	if (ft_memcmp(".cub", &name[i], 4) == 0)
		return (1);
	return (0);
}

int		main(int size, char **arg)
{
	int		map;
	int		screen;

	map = 1;
	screen = 1;
	if (size < 2)
		write(2, "Error\nNot enough arguments sent!\n", 33);
	else if (size > 3)
		write(2, "Error\nToo many arguments sent!\n", 31);
	if (size == 2 || size == 3)
		map = ft_map_name(arg[1]);
	if (size == 3)
		screen = ft_screen_name(arg[2]);
	if (map == 0)
		write(2, "Error\nMap file name not valied!\n", 32);
	if (screen == 0)
		write(2, "Error\nThird argument is not spelled correctly!\n", 47);
	if (size == 2 && map)
		ft_cub(arg[1]);
	else if (size == 3 && map && screen)
		ft_screen(arg[1]);
	return (0);
}
