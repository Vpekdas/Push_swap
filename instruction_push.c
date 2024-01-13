/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:58:57 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/13 15:42:51 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **a, t_list **b, int p)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	if (p == PRINT)
		ft_printf("pa\n");
}

void	ft_pb(t_list **b, t_list **a, int p)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	if (p == PRINT)
		ft_printf("pb\n");
}
