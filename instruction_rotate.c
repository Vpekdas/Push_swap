/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:29:27 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 11:57:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **list, int t)
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
	if (t == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_list **list, int t)
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
	if (t == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_list **list, t_list **list2)
{
	if (!list || (!list2))
		return ;
	ft_ra(list, 0);
	ft_rb(list2, 0);
	ft_printf("rr\n");
}
