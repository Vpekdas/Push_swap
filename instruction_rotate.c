/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:29:27 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/08 17:25:39 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_instruction_ra(t_list **list)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	while (current)
	{
		temp = current->content;
		if (current->next)
		{
			current->content = current->next->content;
			current->next->content = temp;
		}
		current = current->next;
	}
}

void	ft_instruction_rb(t_list **list)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	while (current)
	{
		temp = current->content;
		if (current->next)
		{
			current->content = current->next->content;
			current->next->content = temp;
		}
		current = current->next;
	}
}

// int	main () {
// 	t_list	*node1 = ft_lstnew(1);
// 	t_list	*node2 = ft_lstnew(2);
// 	t_list	*node3 = ft_lstnew(3);
// 	t_list	*node4 = ft_lstnew(4);


// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;


// 	t_list	*current = node1;
// 	ft_printf("BEFORE FUNCTION : ");
// 	while(current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	ft_instruction_ra_rb(&node1);

// 	current = node1;
// 	ft_printf("AFTER FUNCTION : ");
// 	while(current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);
// }

void	ft_instruction_rr(t_list **list, t_list **list2)
{
	if (!list || !(*list2))
		return ;
	ft_instruction_ra(list);
	ft_instruction_rb(list2);
	return ;
}

// int	main () {
// 	t_list *node1 = ft_lstnew(1);
// 	t_list *node2 = ft_lstnew(2);
// 	t_list *node3 = ft_lstnew(3);
// 	t_list *node4 = ft_lstnew(4);


// 	t_list *node5 = ft_lstnew(5);
// 	t_list *node6 = ft_lstnew(6);
// 	t_list *node7 = ft_lstnew(7);
// 	t_list *node8 = ft_lstnew(8);


// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;


// 	node5->next = node6;
// 	node6->next = node7;
// 	node7->next = node8;


// 	t_list	*current = node1;
// 	t_list	*current2 = node5;

// 	ft_printf("BEFORE FUNCTION\n");
// 	while(current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);
// 	while(current2)
// 	{
// 		ft_printf("%d -> ", current2->content);
// 		current2 = current2->next;
// 	}
// 	ft_printf("%s\n", current2);

// 	ft_instruction_rr(&node1, &node5);

// 	current = node1;
// 	current2 = node5;

// 	ft_printf("AFTER FUNCTION\n");
// 	while(current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);
// 	while(current2)
// 	{
// 		ft_printf("%d -> ", current2->content);
// 		current2 = current2->next;
// 	}
// 	ft_printf("%s\n", current2);
// }