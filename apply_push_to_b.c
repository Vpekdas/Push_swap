/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_push_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:21:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_ra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c && ft_find_right_pos(*b, c) > 0)
		ft_rr(a, b, PRINT);
	while ((*a)->content != c)
		ft_ra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_ra_rrb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_ra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_rra_rrb(t_list **a, t_list **b, int c)
{
	while (((*a)->content != c) && (ft_find_right_pos(*b, c) > 0))
		ft_rrr(a, b, PRINT);
	while ((*a)->content != c)
		ft_rra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_rra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_rra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}
