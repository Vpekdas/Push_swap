/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_push_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:05:32 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/05 17:38:11 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

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
