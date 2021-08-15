/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:52:20 by cmalt             #+#    #+#             */
/*   Updated: 2020/04/30 20:54:08 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;
	t_uchar	*arr1;
	t_uchar	ch;

	i = 0;
	arr1 = (t_uchar *)arr;
	ch = (t_uchar)c;
	while (i < n)
	{
		if (arr1[i] == ch)
			return (arr1 + i);
		i++;
	}
	return (0);
}
