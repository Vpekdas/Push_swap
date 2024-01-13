/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_push_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:02:08 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/13 15:50:13 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_ra_rb2(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_right_pos2(a, c);
	if (i < ft_num_pos(b, c))
		i = ft_num_pos(b, c);
	return (i);
}

int	ft_case_rra_rb2(t_list	*a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos2(a, c) > 0)
		i = ft_lstsize(a) - ft_find_right_pos2(a, c);
	i += ft_num_pos(b, c);
	return (i);
}

int	ft_case_rra_rrb2(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos2(a, c) > 0)
		i = ft_lstsize(a) - ft_find_right_pos2(a, c);
	if (i < (ft_lstsize(b) - ft_num_pos(b, c)) && ft_num_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_num_pos(b, c);
	return (i);
}

int	ft_case_ra_rrb2(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_num_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_num_pos(b, c);
	i += ft_find_right_pos2(a, c);
	return (i);
}

int	ft_which_move_a(t_list *a, t_list *b)
{
	t_list	*current;
	int		cost;
	int		move;

	current = b;
	cost = ft_case_ra_rb2(a, b, current->content);
	move = 0;
	while (current)
	{
		move = ft_case_ra_rb2(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_ra_rrb2(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rb2(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rrb2(a, b, current->content);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}
