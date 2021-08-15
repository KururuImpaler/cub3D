/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:24:28 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 10:24:34 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (list == 0)
		return (0);
	if (content == 0)
		list->content = 0;
	else
		list->content = content;
	list->next = 0;
	return (list);
}
