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

void	ft_sa(t_list **a, int t)
{
	int		temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (t == PRINT)
		ft_printf("sa\n");
}

void	ft_sb(t_list **b, int t)
{
	int		temp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	if (t == PRINT)
		ft_printf("sb\n");
}

void	ft_ss(t_list **a, t_list **b, int t)
{
	if (!a || !b)
		return ;
	ft_sa(a, NO_PRINT);
	ft_sb(a, NO_PRINT);
	if (t == PRINT)
		ft_printf("ss\n");
}
