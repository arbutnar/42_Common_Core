/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:27:12 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/02 14:36:57 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
		{
			while (new_lst)
			{
				new_elem = new_lst->next;
				(*del)(new_elem->content);
				free(new_elem);
				new_elem = new_lst;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
