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

void	ft_rra(t_list **a, int p)
{
	int		temp;
	t_list	*current;

	if (!a || !(*a) || !(*a)->next)
		return ;
	current = *a;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*a)->content;
		ft_lstlast(*a)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	if (p == PRINT)
		ft_printf("rra\n");
}

void	ft_rrb(t_list **b, int p)
{
	int		temp;
	t_list	*current;

	if (!b || !(*b) || !(*b)->next)
		return ;
	current = *b;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*b)->content;
		ft_lstlast(*b)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	if (p == PRINT)
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **a, t_list **b, int p)
{
	if (!a || !(b))
		return ;
	ft_rra(a, NO_PRINT);
	ft_rrb(b, NO_PRINT);
	if (p == PRINT)
		ft_printf("rrr\n");
}
