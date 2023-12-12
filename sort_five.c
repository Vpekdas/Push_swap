/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 15:32:48 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	main () {
	t_list	*node1 = ft_lstnew(75);
	t_list	*node2 = ft_lstnew(12);
	t_list	*node3 = ft_lstnew(90);
	t_list	*node4 = ft_lstnew(124);
	t_list	*node5 = ft_lstnew(74);

	t_list *list1 = node1;
	t_list *list2 = NULL;
	t_list	*currrent = NULL;


	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	currrent = list1;

	ft_printf("LINK\n");
	while (currrent)
	{
		ft_printf("%d -> ", currrent->content);
		currrent = currrent->next;
	}
	ft_printf("%s\n", currrent);

	ft_instruction_pb(&list2, &node1);
	
	currrent = node2;
	ft_printf("FIRST LINK\n");
	while (currrent)
	{
		ft_printf("%d -> ", currrent->content);
		currrent = currrent->next;
	}
	ft_printf("%s\n", currrent);

	currrent = node1;
	ft_printf("SECOND LINK\n");
	while (currrent)
	{
		ft_printf("%d -> ", currrent->content);
		currrent = currrent->next;
	}
	ft_printf("%s\n", currrent);



}