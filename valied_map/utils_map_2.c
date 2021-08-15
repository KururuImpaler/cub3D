/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_valied_2(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		ft_valied_1(char *s1, char *s2, int *i)
{
	while (s2[*i] == '2')
		*i += 1;
	while (s2[*i] == '3')
	{
		if (s1[*i] == '0')
			return (0);
		*i += 1;
	}
	return (1);
}

int		ft_valied(char *s1, char *s2, int i)
{
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		while (s2[i] == '0')
		{
			if (s1[i] == '3')
				return (0);
			i++;
		}
		if (s2[i] == '\0')
			return (1);
		if (s2[i] != '1')
			return (0);
		i++;
		while (s2[i] == '2' || s2[i] == '3')
			if (ft_valied_1(s1, s2, &i) == 0)
				return (0);
		if (s2[i] != '1')
			return (0);
		if (s1[i] != '\0')
			i++;
	}
	return (1);
}

void	ft_wall_string(char *s, char *s1, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			s1[i] = '0';
		if (s[i] != ' ')
		{
			if ((i == 0 || s[i - 1] == ' ') && s[i] == '1')
				s1[i++] = '1';
			while (s[i] == '1')
				s1[i++] = '2';
			while (ft_memchr("02NSEW", s[i], 6))
				s1[i++] = '3';
			while (s[i] == '1')
				s1[i++] = '2';
			if ((s[i] == ' ' || s[i] == '\0') && s[i - 1] == '1')
				s1[i - 1] = '1';
		}
		else
			i++;
	}
	s1[i] = '\0';
}

int		map_size_line_2(int n, int p, int l1, int l2)
{
	if (n == 0 && (p == 0))
		return (-1);
	if (n < 0)
		return (-10);
	return ((l1 == l2) ? -1 : n);
}
