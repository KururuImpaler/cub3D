/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_size(char *s, t_cub *cub, int i)
{
	int		j;

	i = ft_pass_char(s, i, ' ');
	cub->width = ft_atoi_map(s, &i);
	i = ft_pass_char(s, i, ' ');
	cub->height = ft_atoi_map(s, &i);
	i = ft_pass_char(s, i, ' ');
	j = 0;
	while (s[j] != '\0')
		j++;
	if (j != i || cub->width == 0 || cub->height == 0)
		return (0);
	return (1);
}

int		ft_ceiling(char *s, t_cub *cub, int i, int j)
{
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->c_col[0] = 0))
		cub->c_col[0] = ft_atoi_map(s, &i);
	if (++i && s[i - 1] != ',')
		return (0);
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->c_col[1] = 0))
		cub->c_col[1] = ft_atoi_map(s, &i);
	if (++i && s[i - 1] != ',')
		return (0);
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->c_col[2] = 0))
		cub->c_col[2] = ft_atoi_map(s, &i);
	i = ft_pass_char(s, i, ' ');
	j = ft_strlen(s);
	if (j != i || cub->c_col[0] < 0 || cub->c_col[1] < 0 || cub->c_col[2] < 0)
		return (0);
	if (cub->c_col[0] > 255 || cub->c_col[1] > 255 || cub->c_col[2] > 255)
		return (0);
	cub->c_c = ft_color(cub->c_col[0], cub->c_col[1], cub->c_col[2]);
	return (1);
}

int		ft_floor(char *s, t_cub *cub, int i, int j)
{
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->f_col[0] = 0))
		cub->f_col[0] = ft_atoi_map(s, &i);
	if (++i && s[i - 1] != ',')
		return (0);
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->f_col[1] = 0))
		cub->f_col[1] = ft_atoi_map(s, &i);
	if (++i && s[i - 1] != ',')
		return (0);
	i = ft_pass_char(s, i, ' ');
	if (s[i] >= '0' && s[i] <= '9' && !(cub->f_col[2] = 0))
		cub->f_col[2] = ft_atoi_map(s, &i);
	i = ft_pass_char(s, i, ' ');
	j = ft_strlen(s);
	if (j != i || cub->f_col[0] < 0 || cub->f_col[1] < 0 || cub->f_col[2] < 0)
		return (0);
	if (cub->f_col[0] > 255 || cub->f_col[1] > 255 || cub->f_col[2] > 255)
		return (0);
	cub->f_c = ft_color(cub->f_col[0], cub->f_col[1], cub->f_col[2]);
	return (1);
}

int		get_texture(char *s, t_cub *c, int n, int i)
{
	int		j;
	char	*data;

	j = ft_pass_char(s, i, ' ');
	i = j;
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	if (ft_check_str(&s[i], c))
		return (ft_error_map(c, 4, 0));
	data = &s[j];
	c->tex[n] = mlx_xpm_file_to_image(c->mlx, data, &c->t_w[n], &c->t_h[n]);
	if (c->tex[n] == 0)
		return (ft_error_map(c, 3, 0));
	data = mlx_get_data_addr(c->tex[n], &c->bpp[n], &c->sl, &c->e);
	if ((c->data_t[n] = (t_ui **)malloc(sizeof(t_ui *) * c->t_h[n])) == 0)
		return (ft_error_map(c, 2, 0));
	j = -1;
	while (++j < c->t_h[n] - 1)
	{
		c->data_t[n][j] = (t_ui *)data;
		data += c->sl;
	}
	c->data_t[n][j] = (t_ui *)data;
	return (1);
}

int		ft_parser(char *line, int n, int i, t_cub *cub)
{
	i = ft_pass_char(line, i, ' ');
	if (n == 2)
	{
		if (line[i] == 'R')
			return (ft_size(&line[i + 1], cub, 0));
		if (line[i] == 'C')
			return (ft_ceiling(&line[i + 1], cub, 0, 0));
		if (line[i] == 'F')
			return (ft_floor(&line[i + 1], cub, 0, 0));
	}
	if (n == 3)
	{
		if (line[i] == 'W' && line[i + 1] == 'E')
			return (get_texture(&line[i + 2], cub, 0, 0));
		if (line[i] == 'S' && line[i + 1] == 'O')
			return (get_texture(&line[i + 2], cub, 1, 0));
		if (line[i] == 'N' && line[i + 1] == 'O')
			return (get_texture(&line[i + 2], cub, 2, 0));
		if (line[i] == 'E' && line[i + 1] == 'A')
			return (get_texture(&line[i + 2], cub, 3, 0));
		if (line[i] == 'S' && line[i + 1] == ' ')
			return (get_texture(&line[i + 1], cub, 4, 0));
	}
	return (0);
}
