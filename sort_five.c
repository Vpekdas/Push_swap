/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_ra_multiple(t_list **stack_a, int pos)
{
	while (pos--)
		ft_ra(stack_a);
}

void	ft_rra_multiple(t_list **stack_a, int pos)
{
	while (pos--)
		ft_rra(stack_a);
}

int	ft_find_biggest(t_list **a)
{
	int	num;

	num = (*a)->content;
	while ((*a))
	{
		if ((*a)->content > num)
			num = (*a)->content;
		(*a) = (*a)->next;
	}
	return (num);
}

int	ft_find_smaller(t_list **a)
{
	int	num;

	num = (*a)->content;
	while ((*a))
	{
		if ((*a)->content <= num)
			num = (*a)->content;
		(*a) = (*a)->next;
	}
	return (num);
}

void	ft_rotate_multiple(t_list **a, int range_pos)
{
	int	len;

	len = ft_lstsize(*a);
	if (range_pos < len / 2)
		(ft_ra_multiple(a, range_pos));
	else
		(ft_rra_multiple(a, range_pos));
}

void	ft_sort_five(t_list	**stack_a, t_list	**stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
}
// int	main (int argc, char **argv)
// {
// 	t_list	*list = ft_linked_list(argc, argv);
// 	t_list	*list2 = NULL;
// 	t_list	*current = list;

// 	ft_printf("BEFORE SORTING\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	ft_sort_five(&list, &list2);

// 	current = list;

// 	ft_printf("AFTER SORTING IN STACK A\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	current = list2;

// 	ft_printf("AFTER SORTING IN STACK B\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);
// }