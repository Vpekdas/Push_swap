/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:52:38 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction_ss(t_list **list, t_list **list2)
{
	if (!list || !list2)
		return ;
	ft_instruction_sa(list);
	ft_instruction_sb(list2);
	return ;
}
