/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_push_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/04 15:05:07 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_apply_ra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c && ft_find_right_pos(*b, c) > 0)
		ft_rr(a, b);
	while ((*a)->content != c)
		ft_ra(a, 1);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, 1);
	ft_pb(a, b);
	return (-1);
}

int	ft_apply_ra_rrb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_ra(a, 1);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, 1);
	ft_pb(a, b);
	return (-1);
}

int	ft_apply_rra_rrb(t_list **a, t_list **b, int c)
{
	while (((*a)->content != c) && (ft_find_right_pos(*b, c) > 0))
		ft_rrr(a, b);
	while ((*a)->content != c)
		ft_rra(a, 1);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, 1);
	ft_pb(a, b);
	return (-1);
}

int	ft_apply_rra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_rra(a, 1);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, 1);
	ft_pb(a, b);
	return (-1);
}
