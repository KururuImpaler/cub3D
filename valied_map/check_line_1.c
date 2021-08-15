/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_check(int i, t_cub *cub)
{
	cub->map_var[i] += 1;
	if (i < 3)
		return (2);
	if (i > 2 && i < 8)
		return (3);
	return (0);
}

int		false_1(int *c)
{
	if (!c[3] && (c[8] || c[12]) && !c[4] && !c[5] && !c[6] && !c[7] && !c[11])
		return (1);
	return (0);
}

int		false_2(int *c)
{
	if (!c[0] && c[10] && !c[1] && !c[2] && !c[9] && c[11])
		return (1);
	return (0);
}

int		false_3(int *c)
{
	if (!c[2] && !c[3] && !c[4] && !c[5] && !c[6] && !c[7] && !c[9] && !c[11])
		return (1);
	return (0);
}

int		ft_true_false(int *c, t_cub *cub)
{
	if (!c[0] && c[10] && !c[8] && !c[1] && !c[12] && false_3(c))
		return (4);
	if (c[0] && c[10] && !c[1] && !c[2] && !c[9] && false_1(c))
		return (ft_check(0, cub));
	if (!c[0] && c[10] && c[1] && !c[2] && c[9] && false_1(c))
		return (ft_check(1, cub));
	if (!c[0] && c[10] && !c[1] && c[2] && c[9] && false_1(c))
		return (ft_check(2, cub));
	if (c[3] && !c[4] && !c[5] && !c[6] && !c[7] && false_2(c))
		return (ft_check(3, cub));
	if (!c[3] && c[4] && !c[5] && !c[6] && !c[7] && false_2(c))
		return (ft_check(4, cub));
	if (!c[3] && !c[4] && c[5] && !c[6] && !c[7] && false_2(c))
		return (ft_check(5, cub));
	if (!c[3] && !c[4] && !c[5] && c[6] && !c[7] && false_2(c))
		return (ft_check(6, cub));
	if (!c[3] && !c[4] && !c[5] && !c[6] && c[7] && false_2(c))
		return (ft_check(7, cub));
	if (!c[0] && !c[8] && !c[1] && c[12] && false_3(c))
		return (5);
	return (0);
}
