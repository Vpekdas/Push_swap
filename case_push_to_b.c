/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:00:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 11:56:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_ra_rb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_right_pos(b, c);
	if (i < ft_num_pos(a, c))
		i = ft_num_pos(a, c);
	return (i);
}

int	ft_case_rra_rb(t_list	*a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_num_pos(a, c) > 0)
		i = ft_lstsize(a) - ft_num_pos(a, c);
	i += ft_find_right_pos(b, c);
	return (i);
}

int	ft_case_rra_rrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_find_right_pos(b, c);
	if (i < (ft_lstsize(a) - ft_num_pos(a, c)) && ft_num_pos(a, c) > 0)
		i = ft_lstsize(a) - ft_num_pos(a, c);
	return (i);
}

int	ft_case_ra_rrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_find_right_pos(b, c);
	i += ft_num_pos(a, c);
	return (i);
}

int	ft_which_move_b(t_list *a, t_list *b)
{
	t_list	*current;
	int		cost;
	int		move;

	current = a;
	cost = ft_case_rra_rrb(a, b, current->content);
	move = 0;
	while (current)
	{
		move = ft_case_ra_rb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_ra_rrb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rrb(a, b, current->content);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}
