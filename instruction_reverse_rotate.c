/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:23:19 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 11:12:17 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_instruction_rra(t_list **list)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*list)->content;
		ft_lstlast(*list)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	ft_printf("rra\n");
}

void	ft_instruction_rrb(t_list **list)
{
	int		temp;
	t_list	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	temp = 0;
	while (current)
	{
		temp = ft_lstlast(*list)->content;
		ft_lstlast(*list)->content = current->content;
		current->content = temp;
		current = current->next;
	}
	ft_printf("rrb\n");
}

void	ft_instruction_rrr(t_list **list, t_list **list2)
{
	if (!list || !(*list2))
		return ;
	ft_instruction_rra(list);
	ft_instruction_rrb(list2);
	ft_printf("rrr\n");
}
