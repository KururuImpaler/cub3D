/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_close(int fd, int i)
{
	close(fd);
	return (i);
}

int		ft_check_2(int *var, int i)
{
	while (i < 8 && var[i] == 1)
		i++;
	if (i < 8)
		return (1);
	return (0);
}

int		ft_pass_char(char *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

int		ft_check_str(char *s, t_cub *cub)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[j] == ' ')
		j++;
	if (j == i)
	{
		j = -1;
		while (++j > -1 && s[j] != '\0')
		{
			cub->len += 1;
			s[j] = '\0';
		}
		return (0);
	}
	return (1);
}

int		string_if_2(int *i, char c1, char c2)
{
	if (c1 == '1')
		i[12] = 1;
	else if (c1 >= '0' && c1 <= '9')
		i[8] = 1;
	else if (c1 == ',' && c2 == ' ')
		i[9] = 1;
	else if (c1 == ' ')
		i[10] = 1;
	else
		i[11] = 1;
	return (0);
}
