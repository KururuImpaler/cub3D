/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:48:54 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/01 13:48:59 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	i;

	size_dst = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= size_dst)
		return (ft_strlen(src) + size);
	while ((size_dst + i) < size - 1 && src[i] != 0)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	while (src[i] != 0)
		i++;
	return (size_dst + i);
}
