/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_bmp_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	write(fd, "BM", 2);
	t = 14 + 40 + cub->width * cub->height * 4;
	write(fd, &t, sizeof(t));
	d = 0;
	write(fd, &d, sizeof(d));
	write(fd, &d, sizeof(d));
	t = 14 + 40;
	write(fd, &t, sizeof(t));
}

void	ft_image_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	t = 40;
	write(fd, &t, sizeof(t));
	t = cub->width;
	write(fd, &t, sizeof(t));
	t = cub->height;
	write(fd, &t, sizeof(t));
	d = 1;
	write(fd, &d, sizeof(d));
	d = 32;
	write(fd, &d, sizeof(d));
	t = 0;
	write(fd, &t, sizeof(t));
	t = cub->width * cub->height * 4;
	write(fd, &t, sizeof(t));
	t = 2795;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
	t = 0;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
}

void	ft_bmp(t_cub *cub, int i)
{
	int		fd;

	fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, 00600 | 00060 | 00006);
	if (fd < 0)
		ft_exit(cub, 4);
	ft_bmp_header(cub, fd);
	ft_image_header(cub, fd);
	while (i-- > 0)
		write(fd, &cub->data_img[i][0], cub->width * 4);
	close(fd);
}

void	ft_window_s(t_cub *cub)
{
	int		x;
	int		check;

	x = -1;
	check = 0;
	while (++x < cub->width)
	{
		ft_angle(cub);
		ft_raycast(cub, x, check);
		check = ft_draw(cub, x);
	}
	ft_bmp(cub, cub->height);
}

int		ft_position_s(t_cub *cub)
{
	cub->dir_angle = cub->alpha;
	cub->alpha += 30;
	cub->beta = 30;
	ft_window_s(cub);
	ft_exit_2(cub);
	return (0);
}
