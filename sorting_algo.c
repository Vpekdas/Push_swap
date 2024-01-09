/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:06:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 17:22:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **a)
{
	int	top;
	int	bot;

	top = (*a)->content;
	bot = (*a)->next->content;
	if (top > bot)
		ft_sa(a, 1);
}

void	ft_sort_three(t_list **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if (top > mid && mid < bot && bot > top)
		ft_sa(a, PRINT);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_sa(a, PRINT);
		ft_rra(a, PRINT);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_ra(a, PRINT);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_sa(a, PRINT);
		ft_ra(a, PRINT);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(a, PRINT);
}

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

void	ft_sort_hundred_and_more(t_list **a, t_list **b)
{
	int	smallest;
	int	pos;

	smallest = ft_find_smaller(*a);
	pos = ft_num_pos(*a, smallest);
	ft_pb(a, b, PRINT);
	ft_pb(a, b, PRINT);
	ft_sort_till_3_remains(a, b);
	ft_sort_three(a);
	ft_sort_till_empty(a, b);
	if (pos < ft_lstsize(*a) / 2)
		while ((*a)->content != ft_find_smaller(*a))
			ft_rra(a, PRINT);
	else
		while ((*a)->content != ft_find_smaller(*a))
			ft_ra(a, PRINT);
}
