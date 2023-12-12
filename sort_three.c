/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:08:28 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 11:37:12 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_sort_three(t_list **list)
{
	int	top;
	int	mid;
	int	bot;

	top = (*list)->content;
	mid = (*list)->next->content;
	bot = (*list)->next->next->content;

	if (top > mid && mid < bot && bot > top)
		ft_instruction_sa(list);
	if (top > mid && mid > bot && bot < top)
	{
		ft_instruction_sa(list);
		ft_instruction_rra(list);
	}
	if (top > mid && mid < bot && bot < top)
		ft_instruction_ra(list);
	if (top < mid && mid > bot && bot > top)
	{
		ft_instruction_sa(list);
		ft_instruction_ra(list);
	}
	if (top < mid && mid > bot && bot < top)
		ft_instruction_ra(list);
}
