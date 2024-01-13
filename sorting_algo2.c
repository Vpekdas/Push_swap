/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:58:29 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/13 15:43:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_till_3_remains(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	while (ft_lstsize(*a) > 3 && ft_check_sorted(*a) == 1)
	{
		current = *a;
		i = ft_which_move_b(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_ra_rb(*a, *b, current->content))
				i = ft_apply_ra_rb(a, b, current->content);
			else if (i == ft_case_ra_rrb(*a, *b, current->content))
				i = ft_apply_ra_rrb(a, b, current->content);
			else if (i == ft_case_rra_rb(*a, *b, current->content))
				i = ft_apply_rra_rb(a, b, current->content);
			else if (i == ft_case_rra_rrb(*a, *b, current->content))
				i = ft_apply_rra_rrb(a, b, current->content);
			else
				current = current->next;
		}
	}
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
