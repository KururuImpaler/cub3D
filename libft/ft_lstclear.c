/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:48:51 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/04 11:48:54 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*list;

	if (*lst != 0)
	{
		list = *lst;
		while (list != 0)
		{
			next = list->next;
			del(list->content);
			list->next = 0;
			free(list);
			list = next;
		}
		*lst = 0;
	}
}
