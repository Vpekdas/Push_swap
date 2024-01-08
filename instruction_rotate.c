/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:29:27 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:24:35 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **list, int p)
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
	if (p == PRINT)
		ft_printf("ra\n");
}

void	ft_rb(t_list **list, int p)
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
	if (p == PRINT)
		ft_printf("rb\n");
}

void	ft_rr(t_list **list, t_list **list2, int p)
{
	if (!list || (!list2))
		return ;
	ft_ra(list, NO_PRINT);
	ft_rb(list2, NO_PRINT);
	if (p == PRINT)
		ft_printf("rr\n");
}
