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

void	ft_instruction_sa(t_list **list)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	ft_printf("sa\n");
}

void	ft_instruction_sb(t_list **list)
{
	int		temp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	temp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = temp;
	ft_printf("sb\n");
}

void	ft_instruction_ss(t_list **list, t_list **list2)
{
	if (!list || !list2)
		return ;
	ft_instruction_sa(list);
	ft_instruction_sb(list2);
	ft_printf("ss\n");
}
