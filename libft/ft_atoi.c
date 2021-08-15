/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:58:16 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/01 20:58:20 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_to_int(const char *arr, int n)
{
	int		i;
	int		nbr;
	int		len;

	i = 0;
	nbr = 0;
	len = 0;
	while (arr[i] >= '0' && arr[i] <= '9')
	{
		nbr = nbr * 10 + (arr[i] - 48);
		if (len >= 19 && n == 1)
			return (nbr = -1);
		else if (len >= 19 && n == -1)
			return (nbr = 0);
		if (nbr != 0)
			len++;
		i++;
	}
	return (nbr * n);
}

int			ft_atoi(const char *arr)
{
	int		n;
	int		i;

	n = 1;
	i = 0;
	while (arr[i] == '\t' || arr[i] == '\v' || arr[i] == '\r' || \
	arr[i] == '\f' || arr[i] == '\n' || arr[i] == ' ')
		i++;
	if (arr[i] == '-')
	{
		i++;
		n = -1;
	}
	else if (arr[i] == '+')
		i++;
	return (ft_char_to_int(&arr[i], n));
}
