/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:33:57 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/02 13:34:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	i;
	size_t	len_s;

	buf = 0;
	i = 0;
	len_s = ft_strlen(s);
	buf = (char *)malloc(len_s + 1 * sizeof(char));
	if (buf == 0)
		return (0);
	while (i < len_s)
	{
		buf[i] = s[i];
		i++;
	}
	buf[len_s] = '\0';
	return (buf);
}
