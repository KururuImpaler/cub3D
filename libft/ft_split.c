/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:18:37 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/03 11:18:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_n_start_finish(char *s, char c, size_t i, char *check)
{
	int		result;

	result = 0;
	while (s[i] != 0)
	{
		if (i == 0 && s[i] != c && ft_memcmp(check, "n", 1) == 0)
			result++;
		else if (i > 0 && s[i] != c && s[i - 1] == c && \
		ft_memcmp(check, "n", 1) == 0)
			result++;
		else if (i == 0 && s[i] != c && ft_memcmp(check, "start", 5) == 0)
			return (i);
		else if (i > 0 && s[i] != c && s[i - 1] == c && \
		ft_memcmp(check, "start", 5) == 0)
			return (i);
		else if (s[i] == c && ft_memcmp(check, "finish", 6) == 0)
			break ;
		i++;
	}
	if (ft_memcmp(check, "n", 1) == 0)
		return (result);
	return (i);
}

static char		**ft_free(char **buf, size_t n)
{
	while (n != 0)
	{
		free(buf[n]);
		buf[n] = 0;
		n--;
	}
	free(buf[0]);
	buf[0] = 0;
	free(buf);
	buf = 0;
	return (0);
}

static char		**ft_cpy_str(char *s, char c, char **buf, size_t n)
{
	size_t	len;
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (i < n)
	{
		start = ft_n_start_finish(s, c, start, "start");
		len = ft_n_start_finish(s, c, start + 1, "finish") - start + 1;
		buf[i] = (char *)ft_calloc(len, sizeof(char));
		if (buf[i] == 0)
			return (ft_free(buf, n));
		ft_strlcpy(buf[i], &s[start], len);
		start = start + len;
		i++;
	}
	buf[i] = 0;
	return (buf);
}

char			**ft_split(char const *s, char c)
{
	char	**buf;
	size_t	n;

	buf = 0;
	if (s == 0)
		return (0);
	n = ft_n_start_finish((char *)s, c, 0, "n");
	buf = (char **)ft_calloc(n + 1, sizeof(char *));
	if (buf == 0)
		return (0);
	buf = ft_cpy_str((char *)s, c, buf, n);
	if (buf == 0)
		return (0);
	return (buf);
}
