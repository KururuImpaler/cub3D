/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valied_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_atoi_map(char *s, int *i)
{
	int		nbr;
	int		j;

	j = *i;
	nbr = 0;
	while (s[j] >= '0' && s[j] <= '9' && nbr >= 0)
	{
		nbr = nbr * 10 + s[j] - '0';
		j++;
	}
	while (s[j] >= '0' && s[j] <= '9')
		j++;
	if (nbr < 0)
		nbr = 2147483640;
	*i = j;
	return (nbr);
}

int		ft_error_map(t_cub *cub, int error, int ret)
{
	cub->error = error;
	return (ret);
}

char	*ft_error_map2(t_cub *cub, int error, char *ret)
{
	cub->error = error;
	return (ret);
}

int		ft_minimap_image(t_cub *cub, char *data, int n)
{
	int		i;
	int		j;

	j = cub->width / 6;
	i = cub->height / 6;
	if ((cub->minimap = mlx_new_image(cub->mlx, j, i)) == 0)
		return (ft_error_map(cub, 3, 0));
	data = mlx_get_data_addr(cub->minimap, &cub->i_bpp, &cub->sl, &cub->e);
	if ((cub->data_map = (t_ui **)malloc(i * sizeof(t_ui *))) == 0)
		return (ft_error_map(cub, 2, 0));
	n = -1;
	while (++n < i - 1)
	{
		cub->data_map[n] = (t_ui *)data;
		data += cub->sl;
	}
	cub->data_map[n] = (t_ui *)data;
	return (1);
}

int		ft_map_valied(char *name, t_cub *cub, int fd, int n)
{
	char	*line;

	if ((fd = open(name, O_RDONLY)) < 0)
		return (ft_error_map(cub, 1, 0));
	while ((n = get_line_map(fd, &line, 0, cub)) >= 0 && n < 5)
	{
		if (n > 1 && n < 4)
			n = ft_parser(line, n, 0, cub);
		cub->len += 1;
		if (line != 0)
		{
			cub->len += ft_strlen(line);
			free(line);
		}
		if (n == 0 || n > 3)
			return (ft_close(fd, 0));
	}
	if (n < 0)
		return (ft_close(fd, 0));
	n = ft_map_parse(fd, line, name, cub);
	if (line != 0)
		free(line);
	return (ft_close(fd, n));
}
