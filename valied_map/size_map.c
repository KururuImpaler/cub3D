/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_read_file(int fd, t_cub *cub)
{
	int		n;
	char	c;
	int		i;

	i = 0;
	while (i < cub->len && (n = read(fd, &c, 1)) > 0)
		i++;
	if (n <= 0)
		return (1);
	return (0);
}

int		ft_pl_pos(char c, int *p1)
{
	static int	p = 0;

	*p1 = p;
	if (ft_memchr("NSEW", c, 4) && p == 0)
	{
		p = 1;
		*p1 = p;
		return (0);
	}
	return (1);
}

int		map_size_line(int fd, int *w, int *h, char *c)
{
	int		n;
	int		l1;
	int		p;
	int		l2;

	n = 1;
	l1 = 0;
	l2 = 0;
	ft_pl_pos('k', &p);
	while (n > 0 && *c != '\n')
	{
		if (!ft_memchr(" 012", *c, 4) && ft_pl_pos(*c, &p))
			return (-1);
		if (*c == ' ')
			l1++;
		n = read(fd, c, 1);
		l2++;
	}
	if (n > 0)
		n = read(fd, c, 1);
	if (l2 > *w)
		*w = l2;
	*h += 1;
	return (map_size_line_2(n, p, l1, l2));
}

int		ft_size_map(t_cub *cub, int fd, int w, int h)
{
	int		n;
	char	c;

	if (ft_read_file(fd, cub) || (n = read(fd, &c, 1)) < 0)
		return (ft_error_map(cub, 1, 1));
	while (n > 0)
		n = map_size_line(fd, &w, &h, &c);
	if (n == -10)
		return (ft_error_map(cub, 1, 1));
	if (n < 0)
		return (1);
	cub->map = (char **)malloc((h + 1) * sizeof(char *));
	if (cub->map == 0)
		return (ft_error_map(cub, 2, 1));
	cub->map_size_x = (double)w;
	cub->map_size_y = (double)h;
	return (0);
}
