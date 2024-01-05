/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:32:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/05 15:00:44 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

t_list	*ft_linked_list(int ac, char **av)
{
	int		i;
	t_list	*new_node;
	t_list	*new_list;

	i = 1;
	new_list = NULL;
	while (i < ac)
	{
		new_node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&new_list, new_node);
		i++;
	}
	return (new_list);
}

t_list	*ft_linked_list_split(int ac, char **av)
{
	int		i;
	t_list	*new_node;
	t_list	*new_list;

	i = 0;
	new_list = NULL;
	while (i < ac)
	{
		new_node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&new_list, new_node);
		i++;
	}
	return (new_list);
}

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
