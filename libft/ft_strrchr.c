/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:31:53 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/01 16:32:08 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	ch;

	i = 0;
	str = 0;
	ch = (char)c;
	while (s[i] != 0)
	{
		if (s[i] == ch)
			str = &((char *)s)[i];
		i++;
	}
	if (s[i] == ch)
		str = &((char *)s)[i];
	return (str);
}
