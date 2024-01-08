/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_push_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:05:32 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:24:22 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_ra_rb2(t_list **a, t_list **b, int c)
{
	while ((*b)->content != c && ft_find_right_pos2(*a, c) > 0)
		ft_rr(a, b, PRINT);
	while ((*b)->content != c)
		ft_rb(b, PRINT);
	while (ft_find_right_pos2(*a, c) > 0)
		ft_ra(a, PRINT);
	ft_pa(b, a, PRINT);
	return (-1);
}

int	ft_apply_rra_rb2(t_list **a, t_list **b, int c)
{
	while (ft_find_right_pos2(*a, c) > 0)
		ft_rra(a, PRINT);
	while ((*b)->content != c)
		ft_rb(b, PRINT);
	ft_pa(b, a, PRINT);
	return (-1);
}

int	ft_apply_rra_rrb2(t_list **a, t_list **b, int c)
{
	while (((*b)->content != c) && (ft_find_right_pos2(*a, c) > 0))
		ft_rrr(a, b, PRINT);
	while ((*b)->content != c)
		ft_rrb(b, PRINT);
	while (ft_find_right_pos2(*a, c) > 0)
		ft_rra(a, PRINT);
	ft_pa(b, a, PRINT);
	return (-1);
}

int	ft_apply_ra_rrb2(t_list **a, t_list **b, int c)
{
	while (ft_find_right_pos2(*a, c) > 0)
		ft_ra(a, PRINT);
	while ((*b)->content != c)
		ft_rrb(b, PRINT);
	ft_pa(b, a, PRINT);
	return (-1);
}
