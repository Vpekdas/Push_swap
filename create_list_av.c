/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:32:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 11:57:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*ft_linked_list_if_ac_2(char **av)
{
	t_list	*a;
	int		words;
	char	**str;

	str = ft_split(av[1], ' ');
	if (!str || str[0][0] == '\0')
	{
		ft_free_split(str);
		return (NULL);
	}
	words = ft_count_words(str);
	if (ft_overall_check_split(words, str) == 1)
		return (ft_free_split_and_print_error(str));
	a = ft_linked_list_split(words, str);
	ft_free_split(str);
	return (a);
}
