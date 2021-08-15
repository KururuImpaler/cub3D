/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:13:42 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/03 10:13:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_buf(char const *s1, char const *set, size_t len_s, \
size_t len_set)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	result = 0;
	while (i < len_s)
	{
		j = 0;
		while (j < len_set)
		{
			if (s1[i] == set[j])
			{
				result++;
				break ;
			}
			j++;
		}
		if (j == len_set)
			break ;
		i++;
	}
	return (result);
}

static size_t	ft_finish_buf(char const *s1, char const *set, size_t len_s, \
size_t len_set)
{
	size_t	j;
	size_t	result;

	result = 0;
	while (len_s != 0)
	{
		j = 0;
		while (j < len_set)
		{
			if (s1[len_s] == set[j])
			{
				result++;
				break ;
			}
			j++;
		}
		if (j == len_set)
			break ;
		len_s--;
	}
	return (result);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	len_s;
	size_t	len_set;
	size_t	start;
	size_t	finish;

	buf = 0;
	if (s1 == 0 || set == 0)
		return (0);
	len_s = ft_strlen(s1);
	len_set = ft_strlen(set);
	start = ft_start_buf(s1, set, len_s, len_set);
	finish = len_s - ft_finish_buf(s1, set, len_s - 1, len_set);
	if (start == len_s)
		finish = start;
	buf = (char *)ft_calloc(finish - start + 1, sizeof(char));
	if (buf == 0)
		return (0);
	ft_strlcpy(buf, &s1[start], finish - start + 1);
	return (buf);
}
