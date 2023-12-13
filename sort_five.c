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

void	ft_sort_five(t_list	**stack_a, t_list	**stack_b)
{
	ft_instruction_pb(stack_a, stack_b);
	ft_instruction_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
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