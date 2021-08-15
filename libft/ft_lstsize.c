/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:46:30 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 10:46:32 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		size;

	size = 0;
	if (lst == 0)
		return (size);
	list = lst;
	while (list->next != 0)
	{
		size++;
		list = list->next;
	}
	return (++size);
}
