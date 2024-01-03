/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_push_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:25:01 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/03 15:51:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
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
	i = ft_num_pos(b, c) + i;
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
	i = ft_find_right_pos2(a, c) + i;
	return (i);
}

int	ft_apply_ra_rb2(t_list **a, t_list **b, int c)
{
	while ((*b)->content != c && ft_find_right_pos2(*a, c) > 0)
		ft_rr(a, b);
	while ((*b)->content != c)
		ft_rb(b, 1);
	while (ft_find_right_pos2(*a, c) > 0)
		ft_ra(a, 1);
	ft_pa(b, a);
	return (-1);
}

int	ft_apply_rra_rb2(t_list **a, t_list **b, int c)
{
	while (ft_find_right_pos2(*a, c) > 0)
		ft_rra(a, 1);
	while ((*b)->content != c)
		ft_rb(b, 1);
	ft_pa(b, a);
	return (-1);
}

int	ft_apply_rra_rrb2(t_list **a, t_list **b, int c)
{
	while (((*b)->content != c) && (ft_find_right_pos2(*a, c) > 0))
		ft_rrr(a, b);
	while ((*b)->content != c)
		ft_rrb(b, 1);
	while (ft_find_right_pos2(*a, c) > 0)
		ft_rra(a, 1);
	ft_pa(b, a);
	return (-1);
}

int	ft_apply_ra_rrb2(t_list **a, t_list **b, int c)
{
	while (ft_find_right_pos2(*a, c) > 0)
		ft_ra(a, 1);
	while ((*b)->content != c)
		ft_rrb(b, 1);
	ft_pa(b, a);
	return (-1);
}

int	ft_which_move_a(t_list *a, t_list *b)
{
	t_list	*current;
	int		cost;
	int 	move;

	current = b;
	cost = ft_case_rra_rrb2(a, b, current->content);
	move = 0;
	while (current)
	{
		move = ft_case_ra_rb2(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_ra_rrb2(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rb2(a, b ,current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rrb2(a, b ,current->content);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}

void	ft_sort_till_empty(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	while (ft_lstsize(*b) > 0)
	{
		current = *b;
		i = ft_which_move_a(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_ra_rb2(*a, *b, current->content))
				i = ft_apply_ra_rb2(a, b, current->content);
			else if (i == ft_case_ra_rrb2(*a, *b, current->content))
				i = ft_apply_ra_rrb2(a, b, current->content);
			else if (i == ft_case_rra_rb2(*a, *b, current->content))
				i = ft_apply_rra_rb2(a, b, current->content);
			else if (i == ft_case_rra_rrb2(*a, *b, current->content))
				i = ft_apply_rra_rrb2(a, b, current->content);
			else
				current = current->next;
		}
	}
}