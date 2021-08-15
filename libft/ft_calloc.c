/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:17:28 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/02 12:17:32 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	buf = 0;
	if (nmemb * size > 2147483647)
		return (0);
	buf = malloc(nmemb * size);
	if (buf == 0)
		return (0);
	ft_bzero(buf, nmemb * size);
	return (buf);
}
