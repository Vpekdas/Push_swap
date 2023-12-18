/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:29:18 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/18 14:09:03 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_sort_hundred(t_list **a, t_list **b)
{
	int		chunk;
	int		hold_first;
	int		hold_second;
	t_list	*current;
	int		len;

	b = NULL;
	len = ft_lstsize(*a);
	chunk = len / 5;
	hold_first = 0;
	hold_second = 0;
	current = (*a);
	while (current)
	{
		if (current->content <= chunk)
		{
			hold_first = current->content;
			break ;
		}
		current = current->next;
	}
	current = (*a);
	while (current)
	{
		if (current->content <= chunk && current->content != hold_first)
		{
			hold_second = current->content;
			break ;
		}
		current = current->next;
	}
	ft_printf("%d\n", hold_first);
	ft_printf("%d\n", hold_second);
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

	ft_sort_hundred(&list, &list2);
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