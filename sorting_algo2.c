/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:58:29 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:23:17 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_list **a, t_list **b)
{
	int		pos;
	int		i;

	i = 0;
	ft_pb(a, b, PRINT);
	ft_sort_three(a);
	pos = ft_find_right_pos2(*a, (*b)->content);
	if (pos > ft_lstsize(*a) / 2)
		while (i++ < pos)
			ft_rra(a, PRINT);
	else
		while (i++ < pos)
			ft_ra(a, PRINT);
	ft_pa(b, a, PRINT);
	while ((*a)->content != ft_find_smaller(*a))
		ft_ra(a, PRINT);
}

void	ft_select_and_apply_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1 || !a)
		return ;
	else if (ft_lstsize(*a) == 2)
		ft_sort_two(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	else if (ft_lstsize(*a) == 4)
		ft_sort_four(a, b);
	else
		ft_sort_hundred_and_more(a, b);
}
