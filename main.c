/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:10 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 16:04:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		a = ft_linked_list_if_ac_2(av);
	else if (ac > 2)
	{
		if (ft_overall_check(ac, av) == 1)
			return (ft_print_error());
		a = ft_linked_list(ac, av);
	}
	ft_select_and_apply_sort(&a, &b);
	return (ft_free_list(&a, &b));
}

// int	main (int ac, char **av)
// {
// 	t_list	*list = ft_linked_list(ac, av);
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

// 	ft_sort_four(&list, &list2);

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