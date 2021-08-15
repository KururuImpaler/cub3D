/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:48:56 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/05 18:49:06 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_new_list(t_list *lst, void *(*f)(void *), \
void (*del)(void *))
{
	void	*data;
	t_list	*container;

	data = f(lst->content);
	if (data == 0)
		del(data);
	container = ft_lstnew(data);
	if (container == 0)
		return (0);
	return (container);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*front_list;
	t_list	*container;

	if (lst == 0)
		return (0);
	list = lst;
	front_list = 0;
	while (list != 0)
	{
		if ((container = ft_new_list(list, f, del)) == 0)
		{
			ft_lstadd_back(&front_list, container);
			ft_lstclear(&front_list, del);
			return (0);
		}
		ft_lstadd_back(&front_list, container);
		list = list->next;
	}
	return (front_list);
}
