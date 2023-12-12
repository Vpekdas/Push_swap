/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"


int	main (int argc, char **argv) {

	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	t_list	*current = NULL;

	list1 = ft_linked_list(argc, argv);

	current = list1;
	while(current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

	ft_instruction_pb(&list1, &list2);
	ft_instruction_pb(&list1, &list2);

	current = list2;
	while(current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

}
