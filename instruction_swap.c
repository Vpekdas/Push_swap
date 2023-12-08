/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:13 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:56 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction_sa_sb(t_list **list)
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

void	ft_instruction_ss(t_list **list, t_list **list2)
{
	if (!list || !list2)
		return ;
	ft_instruction_sa_sb(list);
	ft_instruction_sa_sb(list2);
	return ;
}
// int	main() {
// 	t_list *node1 = ft_lstnew(1);
// 	t_list *node2 = ft_lstnew(2);
// 	t_list *node3 = ft_lstnew(3);

// 	t_list *node4 = ft_lstnew(4);
// 	t_list *node5 = ft_lstnew(5);
// 	t_list *node6 = ft_lstnew(6);

// 	node1->next = node2;
// 	node2->next = node3;

// 	node4->next = node5;
// 	node5->next = node6;

// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node1->content, node2->content, node3->content);
// 	ft_printf("BEFORE FUNCTION : %d -> %d -> %d -> null\n", node4->content, node5->content, node6->content);

// 	ft_instruction_ss(&node1, &node4);

// 	t_list *current = node1;
// 	t_list *current2 = node4;
// 	ft_printf("AFTER FUNCTION : ");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	ft_printf("AFTER FUNCTION : ");
// 	while (current2)
// 	{
// 		ft_printf("%d -> ", current2->content);
// 		current2 = current2->next;
// 	}
// 	ft_printf("%s\n", current2);
// }