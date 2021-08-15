/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_window_image(t_cub *cub)
{
	char	*data;
	int		n;

	if ((cub->img = mlx_new_image(cub->mlx, cub->width, cub->height)) == 0)
		return (ft_error_map(cub, 3, 0));
	data = mlx_get_data_addr(cub->img, &cub->i_bpp, &cub->sl, &cub->e);
	if ((cub->data_img = (t_ui **)malloc(cub->height * sizeof(t_ui *))) == 0)
		return (ft_error_map(cub, 2, 0));
	n = -1;
	while (++n < cub->height - 1)
	{
		cub->data_img[n] = (t_ui *)data;
		data += cub->sl;
	}
	cub->data_img[n] = (t_ui *)data;
	return (ft_minimap_image(cub, data, n));
}

int		map_sprites(t_cub *cub, int k)
{
	cub->sprites.all_s = k;
	if ((cub->sprites.height = (int *)malloc(sizeof(int) * (k + 1))) == 0)
		return (ft_error_map(cub, 2, 0));
	if ((cub->sprites.x = (int *)malloc(sizeof(int) * (k + 1))) == 0)
		return (ft_error_map(cub, 2, 0));
	return (1);
}

void	ft_angle_map(t_cub *cub, char c)
{
	if (c == 'S')
		cub->alpha = 0;
	if (c == 'E')
		cub->alpha = 90;
	if (c == 'N')
		cub->alpha = 180;
	if (c == 'W')
		cub->alpha = 270;
	if (cub->width > 1920)
		cub->width = 1920;
	if (cub->height > 1016)
		cub->height = 1016;
	if (cub->width < 800)
		cub->width = 800;
	if (cub->height < 600)
		cub->height = 600;
	cub->delta = (double)60 / (double)cub->width;
	cub->dist = (double)(cub->width / 2) / ft_tan(30) * cub->step_map;
}

int		ft_data_map(t_cub *cub)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < cub->map_size_y)
	{
		j = -1;
		while (++j < cub->map_size_x)
		{
			if (ft_memchr("NSEW", cub->map[i][j], 4))
			{
				cub->pos_x = (double)j * cub->step_map + cub->step_map / 2.0;
				cub->pos_y = (double)i * cub->step_map + cub->step_map / 2.0;
				ft_angle_map(cub, cub->map[i][j]);
			}
			if (cub->map[i][j] == '2')
				k++;
		}
	}
	cub->map_size_x *= cub->step_map;
	cub->map_size_y *= cub->step_map;
	return (map_sprites(cub, k));
}

int		ft_map_parse(int fd1, char *line, char *name, t_cub *cub)
{
	int		fd2;
	int		w_m;
	int		h_m;

	if (ft_check_2(cub->map_var, 0))
		return (0);
	w_m = ft_strlen(line);
	h_m = 1;
	cub->len += w_m + 1;
	if ((fd2 = open(name, O_RDONLY)) < 0)
		return (ft_error_map(cub, 1, 0));
	if (ft_size_map(cub, fd2, w_m, h_m))
		return (0);
	close(fd2);
	if (map_valied(cub, line, fd1) == 0 || ft_window_image(cub) == 0)
		return (0);
	return (1);
}
