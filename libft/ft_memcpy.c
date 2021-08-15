/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:01:22 by cmalt             #+#    #+#             */
/*   Updated: 2020/04/30 16:01:33 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	i;
	t_uchar	*d;
	t_uchar	*s;

	i = 0;
	d = (t_uchar *)destination;
	s = (t_uchar *)source;
	if (destination == 0 && source == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
