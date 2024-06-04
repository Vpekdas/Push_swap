/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:29:27 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 05:03:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_list **a, int p)
{
	int		temp;
	t_list	*current;

	if (!a || !(*a) || !(*a)->next)
		return ;
	current = *a;
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
	if (p == PRINT)
		ft_printf("ra\n");
}

void	ft_rb(t_list **b, int p)
{
	int		temp;
	t_list	*current;

	if (!b || !(*b) || !(*b)->next)
		return ;
	current = *b;
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
	if (p == PRINT)
		ft_printf("rb\n");
}

void	ft_rr(t_list **a, t_list **b, int p)
{
	if (!a || (!b))
		return ;
	ft_ra(a, NO_PRINT);
	ft_rb(b, NO_PRINT);
	if (p == PRINT)
		ft_printf("rr\n");
}
