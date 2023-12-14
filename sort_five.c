/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/14 15:22:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_num_pos(t_list **stack_a, int num)
{
	int	pos;

	pos = 0;
	while (*stack_a)
	{
		if (num == (*stack_a)->content)
			return (pos);
		(*stack_a) = (*stack_a)->next;
		pos++;
	}
	return (pos);
}

void	ft_ra_multiple(t_list **stack_a, int pos)
{
	while (pos--)
		ft_instruction_ra(stack_a);
}

void	ft_rra_multiple(t_list **stack_a, int pos)
{
	while (pos--)
		ft_instruction_rra(stack_a);
}

int	ft_find_big_number(t_list **stack)
{
	int	big;

	big = 0;
	while ((*stack))
	{
		if ((*stack)->content > big)
			big = (*stack)->content;
		(*stack) = (*stack)->next;
	}
	return (big);
}

int	ft_find_small_number(t_list **stack)
{
	int small;

	small = (*stack)->content;
	while ((*stack))
	{
		if (small >= (*stack)->content)
			small = (*stack)->content;
		(*stack) = (*stack)->next;
	}
	return (small);
}


int	ft_which_pos_before_push(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list	*temp;

	temp = *stack_a;

	if ((*stack_b)->content > ft_find_big_number(stack_a) || (*stack_b)->content < ft_find_small_number(stack_a))
		return (0);
	while (temp)
	{
		pos++;
		if (*stack_b && (*stack_b)->content > temp->content && (!temp->next || (*stack_b)->content < temp->next->content))
			return (pos);
		temp = temp->next;
	}
	return (pos);
}

void	ft_revert_multiple(t_list **stack_a, int pos)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (pos < len / 2)
		(ft_ra_multiple(stack_a, pos));
	else
		(ft_rra_multiple(stack_a, pos));
}

void	ft_sort_five(t_list	**stack_a, t_list	**stack_b)
{
	int	pos;

	pos = 0;
	ft_instruction_pb(stack_a, stack_b);
	ft_instruction_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pos = ft_which_pos_before_push(stack_a, stack_b, 0);
	ft_revert_multiple(stack_a, pos);
	ft_instruction_pa(stack_b, stack_a);

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

	ft_sort_five(&list, &list2);

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