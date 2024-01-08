/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 16:31:09 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_read(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			ft_sa(a, 0);
		else if (ft_strcmp(line, "sb\n") == 0)
			ft_sb(b, 0);
		else if (ft_strcmp(line, "ss\n") == 0)
			ft_ss(a, b);
		else if (ft_strcmp(line, "pa\n") == 0)
			ft_pa(b, a);
		else if (ft_strcmp(line, "pb\n") == 0)
			ft_pb(a, b);
		else if (ft_strcmp(line, "ra\n") == 0)
			ft_ra(a, 0);
		else if (ft_strcmp(line, "rb\n") == 0)
			ft_rb(b, 0);
		else if (ft_strcmp(line, "rr\n") == 0)
			ft_rr(a, b);
		else if (ft_strcmp(line, "rra\n") == 0)
			ft_rra(a, 0);
		else if (ft_strcmp(line, "rrb\n") == 0)
			ft_rrb(b, 0);
		else if (ft_strcmp(line, "rrr\n") == 0)
			ft_rrr(a, b);
		else
			ft_printf("Error\n");
		free(line);
		line = get_next_line(0);
	}
	if (ft_check_sorted(*a) == 0 && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		words;
	char	**str;

	b = NULL;
	if (ac < 2)
		return (ft_printf("Error\n"));
	else if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		words = ft_count_words(str);
		if (ft_overall_check_split(words, str) == 1)
			return (ft_free_split(str), (ft_printf("Error\n")));
		a = ft_linked_list_split(words, str);
		ft_free_split(str);
	}
	else if (ac > 2)
	{
		if (ft_overall_check(ac, av) == 1)
			return (ft_printf("Error\n"));
		a = ft_linked_list(ac, av);
	}
	ft_sort_list(&a, &b);
	ft_checker_read(&a, &b);
	return (ft_free_list(&a, &b));
}
