/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:37:10 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:20:48 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstmap.c: Iterates the list `lst` and applies the function `f` to the 
** content of each element. Creates a new list resulting of the successive 
** applications of the function `f`. */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int *), void (*del)(int *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	current = lst;
	while (current)
	{
		new_node = ft_lstnew(*f(&current->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		current = current->next;
	}
	return (new_lst);
}
