/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		string_if(int *i, char c1, char c2)
{
	if (c1 == 'R' && c2 == ' ')
		i[0] = 1;
	else if (c1 == 'F' && c2 == ' ')
		i[1] = 1;
	else if (c1 == 'C' && c2 == ' ')
		i[2] = 1;
	else if (c1 == 'W' && c2 == 'E')
		i[3] = 1;
	else if (c1 == 'S' && c2 == 'O')
		i[4] = 1;
	else if (c1 == 'N' && c2 == 'O')
		i[5] = 1;
	else if (c1 == 'E' && c2 == 'A')
		i[6] = 1;
	else if (c1 == 'S' && c2 == ' ')
		i[7] = 1;
	else
		string_if_2(i, c1, c2);
	return (0);
}

int		ft_string(char *s, t_cub *cub)
{
	int		i;
	int		c[13];

	i = -1;
	while (++i < 13)
		c[i] = 0;
	i = 0;
	while (s[i] != 0)
	{
		string_if(c, s[i], s[i + 1]);
		i++;
	}
	return (ft_true_false(c, cub));
}

int		ft_not_line(char *buf)
{
	if (buf != 0)
		free(buf);
	return (-1);
}

char	*line_copy(char *line, char *buf, char c)
{
	int		i;

	i = -1;
	while (++i > -1 && buf != 0 && buf[i] != 0)
		line[i] = buf[i];
	line[i] = c;
	line[i + 1] = '\0';
	return (line);
}

int		get_line_map(int fd, char **line, int n, t_cub *cub)
{
	int		i;
	char	c;
	char	*buf;

	*line = 0;
	while ((i = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
		n += i;
		buf = *line;
		if ((*line = (char *)malloc(n + 1)) == 0)
			return (ft_not_line(buf));
		*line = line_copy(*line, buf, c);
		if (buf != 0)
			free(buf);
	}
	if (i < 0)
	{
		if (*line != 0)
			free(*line);
		return (ft_error_map(cub, 1, -1));
	}
	return ((*line == 0) ? 1 : ft_string(*line, cub));
}
