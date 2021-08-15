/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 06:54:36 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 06:54:39 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

static char		*ft_int_to_str(int n, char *str, size_t len)
{
	size_t	i;
	size_t	del;

	del = 1;
	i = 0;
	while (++i < len)
		del *= 10;
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		del /= 10;
		n *= -1;
	}
	while (i < len)
	{
		str[i] = n / del + '0';
		n = n - (n / del) * del;
		del /= 10;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	str = 0;
	len = ft_int_len(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", len + 1);
		return (str);
	}
	str = ft_int_to_str(n, str, len);
	return (str);
}
