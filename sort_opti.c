/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:51:12 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/29 15:59:56 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_sort_opti(t_list **a, t_list **b)
{
	int i;

	i = 0;
	ft_pb(a, b);
	ft_pb(a, b);

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

	ft_sort_opti(&list, &list2);

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