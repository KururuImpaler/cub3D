/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

void	ft_copy_line(char *s, char *line, int w)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	while (i < w)
	{
		s[i] = ' ';
		if (i < len)
			s[i] = line[i];
		i++;
	}
	s[i] = '\0';
}

char	*ft_first_line(t_cub *cub, char *line, char **s1)
{
	char	*s;

	if ((s = (char *)malloc(cub->map_size_x + 1)) == 0)
		return (0);
	ft_copy_line(s, line, cub->map_size_x);
	if ((s1[0] = (char *)malloc(cub->map_size_x + 1)) == 0)
	{
		free(s);
		return (0);
	}
	if ((s1[1] = (char *)malloc(cub->map_size_x + 1)) == 0)
	{
		free(s1[0]);
		free(s);
		return (0);
	}
	ft_wall_string(s, s1[0], 0);
	return (s);
}

int		ft_read_line(int fd, char *s, int w, int i)
{
	char	c;
	int		n;

	n = read(fd, &c, 1);
	while (n > 0 && c != '\n' && ++i < w)
	{
		s[i] = c;
		n = read(fd, &c, 1);
	}
	while (++i < w)
		s[i] = ' ';
	s[i] = '\0';
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_next_line(int fd, char **s1, t_cub *cub, int i)
{
	char	*s;

	if ((s = (char *)malloc(cub->map_size_x + 1)) == 0)
	{
		free(s1[0]);
		free(s1[1]);
		return (ft_error_map2(cub, 2, 0));
	}
	if (ft_read_line(fd, s, cub->map_size_x, i))
	{
		free(s1[0]);
		free(s1[1]);
		free(s);
		return (ft_error_map2(cub, 1, 0));
	}
	ft_wall_string(s, s1[1], 0);
	if (ft_valied(s1[0], s1[1], 0) == 0)
	{
		free(s1[0]);
		free(s1[1]);
		free(s);
		return (0);
	}
	ft_wall_string(s, s1[0], 0);
	return (s);
}

int		map_valied(t_cub *cub, char *line, int fd)
{
	char	*s;
	char	*wall[2];
	int		i;

	s = ft_first_line(cub, line, wall);
	if (s == 0)
		return (ft_error_map(cub, 2, 0));
	cub->map[0] = s;
	i = 0;
	while (++i < (int)cub->map_size_y)
	{
		if ((s = ft_next_line(fd, wall, cub, -1)) == 0)
			return (0);
		cub->map[i] = s;
	}
	cub->map[i] = 0;
	free(wall[0]);
	free(wall[1]);
	if (ft_valied_2(s) == 0)
		return (0);
	return (ft_data_map(cub));
}
