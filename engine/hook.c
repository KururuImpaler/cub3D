/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libcub.h"

int		ft_all(t_cub *cub)
{
	int		check;

	check = 0;
	if (cub->key_a || cub->key_d || cub->key_w || cub->key_s)
		check = 1;
	else if (cub->key_left || cub->key_right)
		check = 1;
	if (check || cub->start == 0 || cub->check)
	{
		cub->check = 0;
		cub->start += 1;
		ft_position(cub);
	}
	return (0);
}

int		ft_keys_down(int key, t_cub *cub)
{
	if (key == KEYA)
		cub->key_a = 1;
	else if (key == KEYD)
		cub->key_d = 1;
	else if (key == KEYW)
		cub->key_w = 1;
	else if (key == KEYS)
		cub->key_s = 1;
	else if (key == KEYLEFT)
		cub->key_left = 1;
	else if (key == KEYRIGHT)
		cub->key_right = 1;
	else if (key == KEYM)
	{
		cub->m_map *= -1;
		cub->check = 1;
	}
	else if (key == KEYESC)
		ft_exit(cub, 0);
	else if (key == KEYSHIFT)
		cub->speed *= 2;
	return (0);
}

int		ft_keys_up(int key, t_cub *cub)
{
	if (key == KEYA)
		cub->key_a = 0;
	else if (key == KEYD)
		cub->key_d = 0;
	else if (key == KEYW)
		cub->key_w = 0;
	else if (key == KEYS)
		cub->key_s = 0;
	else if (key == KEYLEFT)
		cub->key_left = 0;
	else if (key == KEYRIGHT)
		cub->key_right = 0;
	else if (key == KEYSHIFT)
		cub->speed /= 2;
	return (0);
}
