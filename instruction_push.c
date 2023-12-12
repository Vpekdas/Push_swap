/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:58:57 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 17:25:53 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_instruction_pa(t_list **list, t_list **list2)
{
	ft_lstadd_front(list, (*list2));
	ft_printf("pa\n") ;
}

void	ft_instruction_pb(t_list **list, t_list **list2)
{
	
	if !(*list)
		return ;
	ft_printf("pb\n") ;
}
