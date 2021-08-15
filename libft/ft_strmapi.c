/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 08:27:04 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 08:27:06 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;

	str = 0;
	if (s == 0)
		return (0);
	if (f == 0)
		return (0);
	len = ft_strlen(s);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	str[len] = '\0';
	while (len-- > 0)
		str[len] = f(len, s[len]);
	return (str);
}
