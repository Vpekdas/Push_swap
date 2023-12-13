/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:58:57 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 17:40:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_instruction_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n") ;
}

void	ft_instruction_pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n") ;
}
