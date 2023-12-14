/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:29:27 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 14:43:36 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_ra(t_list **list)
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
	ft_printf("ra\n");
}

void	ft_rb(t_list **list)
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
	ft_printf("rb\n");
}

void	ft_rr(t_list **list, t_list **list2)
{
	if (!list || !(*list2))
		return ;
	ft_ra(list);
	ft_rb(list2);
	ft_printf("rr\n");
}
