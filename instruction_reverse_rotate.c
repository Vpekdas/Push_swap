/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:23:19 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:24:50 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **list, int p)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*list)->content;
		ft_lstlast(*list)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	if (p == PRINT)
		ft_printf("rra\n");
}

void	ft_rrb(t_list **list, int p)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*list)->content;
		ft_lstlast(*list)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	if (p == PRINT)
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **list, t_list **list2, int p)
{
	if (!list || !(*list2))
		return ;
	ft_rra(list, NO_PRINT);
	ft_rrb(list2, NO_PRINT);
	if (p == PRINT)
		ft_printf("rrr\n");
}
