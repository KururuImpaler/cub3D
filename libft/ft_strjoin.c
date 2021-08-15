/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:34:32 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/02 20:34:37 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buf = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (buf == 0)
		return (0);
	ft_strlcpy(buf, s1, s1_len + 1);
	ft_strlcat(buf, s2, s1_len + s2_len + 1);
	return (buf);
}
