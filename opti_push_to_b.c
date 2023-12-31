/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rotate_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:59:32 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/29 16:33:35 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_ra_rb_b(t_list **a, int c)
{
	int	i;

	i = ft_find_right_pos(b, c);
	if (i < ft_num_pos(a, c))
		i = ft_num_pos(a, c);
	return (i);
}

int	ft_rra_rrb_b(t_list **a, t_list **b, int c)
{
	int i;

	i = 0;
	if (ft_find_right_pos(a, c))
		i = ft_lstsize(*a) - ft_find_right_pos(a, c);
	if ((i < (ft_lstsize(*b) - ft_num_pos(a, (*a)->content)))
		&& ft_num_pos(a, (*a)->content))
		i = ft_lstsize(*b) - ft_num_pos(a, (*a)->content);
	return (i);
}

int	ft_rra_rb_b(t_list	**a, int c)
{
	int	i;

	i = 0;
	if (ft_num_pos(a, (*a)->content))
		i = ft_lstsize(*a) - ft_num_pos(a, (*a)->content);
	i = ft_find_right_pos(a, b) + i;
	return (i);
}

int	ft_ra_rrb_b(t_list **a, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(a, b))
		i = ft_lstsize(*b) - ft_find_right_pos(b, a);
	i = ft_num_pos(a, (*a)->content) + i;
	return (i);
}

int	ft_apply_ra_rb(t_list **a, §, int c)
{
	while ((*a)->content != c && ft_find_right_pos(b, a) > 0)
		ft_rr(a, b);
	while ((*a)->content != c)
		ft_ra(a);
	while (ft_find_right_pos(b, a) > 0)
		ft_rb(b);
	ft_pb(b, a);
	return (-1);
}

int	ft_apply_ra_rrb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_ra(a);
	while (ft_find_right_pos(b, a) > 0)
		ft_rrb(b);
	ft_pb(b, a);
	return (-1);
}

int	ft_apply_rra_rrb(t_list **a, t_list **b, int c)
{
	while (((*a)->content != c) && (ft_find_right_pos(b, a) > 0))
		ft_rrr(a, b);
	while ((*a)->content != c)
		ft_rra(a);
	while (ft_find_right_pos(b, a) > 0)
		ft_rrb(b);
	ft_pb(b, a);
	return (-1);
}

int	ft_apply_rra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_rra(a);
	while (ft_find_right_pos(b, a) > 0)
		ft_rb(b);
	ft_pb(b, a);
	return (-1);
}

int	ft_which_move_b(t_list **a, t_list **b)
{
	t_list	*current;
	int		cost;
	int 	move;

	current = *a;
	cost = ft_rra_rrb_b(a, b);
	move = 0;
	while (current)
	{
		move = ft_ra_rb_b(a, b);
		if (cost > move)
			cost = move;
		move = ft_ra_rrb_b(a, b);
		if (cost > move)
			cost = move;
		move = ft_rra_rb_b(a, b);
		if (cost > move)
			cost = move;
		move = ft_rra_rrb_b(a, b);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}
void	ft_sort_till_3_remains(t_list **a, t_list **b)
{
	int		i;
	t_list	*tmp;

	while (ft_lstsize(*a) > 3)
	{
		tmp = *a;
		i = ft_which_move_b(a, b);
		while (i >= 0)
		{
			if (i == ft_ra_rb_b(a, b))
				i = ft_apply_ra_rb(a, b, tmp->content);
			else if (i == ft_ra_rrb_b(a, b))
				i = ft_apply_ra_rrb(a, b, tmp->content);
			else if (i == ft_rra_rb_b(a, b))
				i = ft_apply_rra_rb(a, b, tmp->content);
			else if (i == ft_rra_rrb_b(a, b))
				i = ft_apply_rra_rrb(a, b, tmp->content);
			else
				tmp = tmp->next;
		}
	}
}