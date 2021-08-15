/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:29:27 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 09:29:30 by cmalt            ###   ########.fr       */
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

static void		ft_int_to_str(int n, size_t len, int fd)
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
		ft_putchar_fd('-', fd);
		i++;
		del /= 10;
		n *= -1;
	}
	while (i < len)
	{
		ft_putchar_fd((n / del + '0'), fd);
		n = n - (n / del) * del;
		del /= 10;
		i++;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	size_t	len;

	len = ft_int_len(n);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_int_to_str(n, len, fd);
}
