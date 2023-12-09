/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:08:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/09 15:08:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	main(int	argc, char **argv)
{
	int		i;
	t_list	*new_list;
	t_list	*current;

	i = 1;
	new_list = ft_linked_list(argc, argv);
	current = new_list;
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	return (0);
}