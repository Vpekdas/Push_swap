/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:10 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/05 15:04:24 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"


int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		words;
	char	**str;

	words = 0;
	b = NULL;
	if (ac < 2)
		return (ft_printf("Error\n"));
	else if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		words = ft_count_words(str);
		if (ft_overall_check_split(words, str) == 1)
			return (ft_printf("Error\n"));
		a = ft_linked_list_split(words, str);
		if (ft_lstsize(a) == 1)
			return (0);
		else if (ft_lstsize(a) == 2)
			ft_sort_two(&a);
		else if (ft_lstsize(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_opti(&a, &b);
	}
	else if (ac > 2)
	{
		if (ft_overall_check(ac, av) == 1)
			return (ft_printf("Error\n"));
		a = ft_linked_list(ac, av);
		if (ft_lstsize(a) == 1)
			return (0);
		else if (ft_lstsize(a) == 2)
			ft_sort_two(&a);
		else if (ft_lstsize(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_opti(&a, &b);
	}
	return (0);
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

// 	ft_sort_opti(&list, &list2);

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

