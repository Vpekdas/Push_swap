/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 18:44:02 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		words;
	char	**str;

	b = NULL;
	if (ac < 2)
		return (ft_print_error());
	else if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		words = ft_count_words(str);
		if (ft_overall_check_split(words, str) == 1)
			return (ft_free_split_and_print_error(str));
		a = ft_linked_list_split(words, str);
		ft_free_split(str);
	}
	else if (ac > 2)
	{
		if (ft_overall_check(ac, av) == 1)
			return (ft_print_error());
		a = ft_linked_list(ac, av);
	}
	ft_checker_read(&a, &b);
	return (ft_free_list(&a, &b));
}
