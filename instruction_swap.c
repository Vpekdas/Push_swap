/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:13 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 11:10:09 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_sa(t_list **list, int t)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	if (t == 1)
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
	if (t == 1)
		ft_printf("sb\n");
}

void	ft_ss(t_list **list, t_list **list2)
{
	if (!list || !list2)
		return ;
	ft_sa(list, 0);
	ft_sb(list2, 0);
	ft_printf("ss\n");
}
