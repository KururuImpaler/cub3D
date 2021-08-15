/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:13:39 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/01 18:13:43 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	len_f;
	size_t	i;

	len_f = 0;
	while (find[len_f] != 0)
		len_f++;
	i = 0;
	while (str[i] != 0 && len >= len_f)
	{
		if (ft_memcmp((char *)str + i, find, len_f) == 0)
			return ((char *)str + i);
		i++;
		len--;
	}
	if (len_f == 0)
		return ((char *)str);
	return (0);
}
