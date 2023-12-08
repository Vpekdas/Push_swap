/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:13 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/07 17:00:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction_sa(t_list **list)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	return ;

}
// int	main() {
// 	t_list *node1 = ft_lstnew(1);
// 	t_list *node2 = ft_lstnew(2);
// 	t_list *node3 = ft_lstnew(3);

// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node1->content, node2->content, node3->content);
// 	ft_instruction_sa(&node1);
// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node1->content, node2->content, node3->content);
// }