/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:51:12 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/02 17:51:15 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*buf;

	buf = 0;
	if (s == 0)
		return (0);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	else if (len > len_s - start)
		len = len_s - start;
	buf = (char *)ft_calloc(len + 1, sizeof(char));
	if (buf == 0)
		return (0);
	ft_strlcpy(buf, &s[start], len + 1);
	return (buf);
}
