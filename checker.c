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

#include "Libft/get_next_line.h"
#include "Libft/libft.h"
#include "push_swap.h"

void	ft_checker_sorted(t_list *a, t_list *b)
{
	if (ft_check_sorted(a) == 0 && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_checker_read2(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(a, NO_PRINT);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(b, NO_PRINT);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(a, b, NO_PRINT);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(a, NO_PRINT);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(b, NO_PRINT);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(a, b, NO_PRINT);
	else
		ft_printf("Error\n");
}

int	ft_gnl(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line != NULL);
}

void	ft_checker_read(t_list **a, t_list **b)
{
	char	*line;

	while (ft_gnl(&line, 0))
	{
		if (ft_strcmp(line, "sa\n") == 0)
			ft_sa(a, NO_PRINT);
		else if (ft_strcmp(line, "sb\n") == 0)
			ft_sb(b, NO_PRINT);
		else if (ft_strcmp(line, "ss\n") == 0)
			ft_ss(a, b, NO_PRINT);
		else if (ft_strcmp(line, "pa\n") == 0)
			ft_pa(b, a, NO_PRINT);
		else if (ft_strcmp(line, "pb\n") == 0)
			ft_pb(a, b, NO_PRINT);
		else
			ft_checker_read2(a, b, line);
		free(line);
	}
	ft_checker_sorted(*a, *b);
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
	ft_checker_read(&a, &b);
	return (ft_free_list(&a, &b));
}
