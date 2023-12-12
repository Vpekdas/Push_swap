/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:32:33 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 15:33:13 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

t_list	*ft_linked_list(int argc, char **argv)
{
	int		i;
	t_list	*new_node;
	t_list	*new_list;

	i = 1;
	new_list = NULL;
	while (i < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&new_list, new_node);
		i++;
	}
	return (new_list);
}
