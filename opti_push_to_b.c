/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:59:32 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_case_ra_rb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_right_pos(b, c);
	if (i < ft_num_pos(a, c))
		i = ft_num_pos(a, c);
	return (i);
}

int	ft_case_rra_rb(t_list	*a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_num_pos(a, c) > 0)
		i = ft_lstsize(a) - ft_num_pos(a, c);
	i = ft_find_right_pos(b, c) + i;
	return (i);
}

int	ft_case_rra_rrb(t_list *a, t_list *b, int c)
{
	int i;

	i = 0;
	if (ft_find_right_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_find_right_pos(b, c);
	if (i < (ft_lstsize(a) - ft_num_pos(a, c)) && ft_num_pos(a, c) > 0)
		i = ft_lstsize(a) - ft_num_pos(a, c);
	return (i);
}

int	ft_case_ra_rrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_find_right_pos(b, c);
	i = ft_num_pos(a, c) + i;
	return (i);
}

int	ft_apply_ra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c && ft_find_right_pos(*b, c) > 0)
		ft_rr(a, b);
	while ((*a)->content != c)
		ft_ra(a);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b);
	ft_pb(a, b);
	return (-1);
}

int	ft_apply_ra_rrb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_ra(a);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b);
	ft_pb(a, b);
	return (-1);
}
int	ft_apply_rra_rrb(t_list **a, t_list **b, int c)
{
	while (((*a)->content != c) && (ft_find_right_pos(*b, c) > 0))
		ft_rrr(a, b);
	while ((*a)->content != c)
		ft_rra(a);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b);
	ft_pb(a, b);
	return (-1);
}
int	ft_apply_rra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_rra(a);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b);
	ft_pb(a, b);
	return (-1);
}
int	ft_which_move_b(t_list *a, t_list *b)
{
	t_list	*current;
	int		cost;
	int 	move;

	current = a;
	cost = ft_case_rra_rrb(a, b, current->content);
	move = 0;
	while (current)
	{
		move = ft_case_ra_rb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_ra_rrb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rb(a, b ,current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rrb(a, b ,current->content);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}

void	ft_sort_till_3_remains(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	while (ft_lstsize(*a) > 3)
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

void	ft_sort_opti(t_list **a, t_list **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	ft_sort_till_3_remains(a, b);
	ft_sort_three(a);
}

int	main (int argc, char **argv)
{
	t_list	*list = ft_linked_list(argc, argv);
	t_list	*list2 = NULL;
	t_list	*current = list;

	ft_printf("BEFORE SORTING\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

	ft_sort_opti(&list, &list2);

	current = list;

	ft_printf("AFTER SORTING IN STACK A\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

	current = list2;

	ft_printf("AFTER SORTING IN STACK B\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);
}