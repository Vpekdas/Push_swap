/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:10 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/13 15:43:13 by vopekdas         ###   ########.fr       */
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
