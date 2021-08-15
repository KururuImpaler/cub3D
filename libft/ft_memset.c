/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:58:35 by cmalt             #+#    #+#             */
/*   Updated: 2020/04/30 15:58:54 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t	i;
	t_uchar	*d;
	t_uchar	ch;

	i = 0;
	d = (t_uchar *)destination;
	ch = (t_uchar)c;
	while (i < n)
	{
		d[i] = ch;
		i++;
	}
	return (destination);
}
