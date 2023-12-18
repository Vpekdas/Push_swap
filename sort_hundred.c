/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:29:18 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/18 11:53:38 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_sort_hundred(t_list **a)
{
	int		chunk;
	int		hold_first;
	int		hold_second;
	t_list	*current;
	int		len;

	len = ft_lstsize(*a);
	chunk = ft_find_biggest(a) / 5;
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
}