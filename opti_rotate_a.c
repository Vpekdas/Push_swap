/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rotate_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:59:32 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/29 16:33:35 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_ra_rb(t_list **a, t_list **b)
{
	int	i;

	i = ft_find_right_pos(b, a);
	if (i < ft_num_pos(b, (*a)->content))
		i = ft_num_pos(b, (*a)->content);
	return (i);
}

int	ft_rra_rrb(t_list **a, t_list **b)
{
	int i;

	i = 0;
	if (ft_find_right_pos(b, a))
		i = ft_lstsize(*b) - ft_find_right_pos(b, a);
	if ((i < (ft_lstsize(*a) - ft_num_pos(a, (*a)->content)))
		&& ft_num_pos(a, (*a)->content))
		i = ft_lstsize(*a) - ft_num_pos(a, (*a)->content);
	return (i);
}

int	ft_rra_rb(t_list	**a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_num_pos(a, (*a)->content))
		i = ft_lstsize(*a) - ft_num_pos(a, (*a)->content);
	i = ft_find_right_pos(b, a) + i;
	return (i);
}

int	ft_ra_rrb(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(b, a))
		i = ft_lstsize(*b) - ft_find_right_pos(b, a);
	i = ft_num_pos(a, (*a)->content) + i;
	return (i);
}

int	ft_which_rotate_b(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	i = ft_rra_rrb(a, b);
	current = *a;
	while (current)
	{

		current = current->next;
	}
	return (i);
}