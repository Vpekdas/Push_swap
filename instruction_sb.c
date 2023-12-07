/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:13 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/07 17:00:15 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction_sb(t_list **list)
{
	int		temp;
	t_list	*first;
	t_list	*second;


	if (!list)
		return ;
	first = *list;
	if (first->next == NULL)
		return ;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;

}
// int	main() {
// 	t_list *node1 = ft_lstnew(1);
// 	t_list *node2 = ft_lstnew(2);
// 	t_list *node3 = ft_lstnew(3);

// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node1->content, node2->content, node3->content);
// 	ft_instruction_sb(&node1);
// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node1->content, node2->content, node3->content);
// }