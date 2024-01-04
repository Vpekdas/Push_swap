/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:32:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/04 16:47:11 by vopekdas         ###   ########.fr       */
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
