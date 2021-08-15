/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:01:22 by cmalt             #+#    #+#             */
/*   Updated: 2020/04/30 16:01:33 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t	i;
	t_uchar	*d;
	t_uchar	*s;
	t_uchar	ch;

	i = 0;
	s = (t_uchar *)source;
	d = (t_uchar *)destination;
	ch = (t_uchar)c;
	while (i < n)
	{
		d[i] = s[i];
		if (ch == s[i])
			return (destination + i + 1);
		i++;
	}
	return (0);
}
