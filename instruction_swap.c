/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:13 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:25:00 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **list, int t)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	if (t == PRINT)
		ft_printf("sa\n");
}

void	ft_sb(t_list **list, int t)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	if (t == PRINT)
		ft_printf("sb\n");
}

void	ft_ss(t_list **list, t_list **list2, int t)
{
	if (!list || !list2)
		return ;
	ft_sa(list, NO_PRINT);
	ft_sb(list2, NO_PRINT);
	if (t == PRINT)
		ft_printf("ss\n");
}
