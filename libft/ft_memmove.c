/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:01:22 by cmalt             #+#    #+#             */
/*   Updated: 2020/04/30 16:01:33 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	t_uchar	*d;
	t_uchar	*s;

	d = (t_uchar *)destination;
	s = (t_uchar *)source;
	if (destination == 0 && source == 0)
		return (0);
	if (destination < source)
		return (ft_memcpy(d, s, n));
	while (n-- > 0)
		d[n] = s[n];
	return (destination);
}
