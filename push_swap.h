/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"

void	ft_instruction_pa_pb(t_list **list, t_list **list2);
void	ft_instruction_sa_sb(t_list **list);
void	ft_instruction_ss(t_list **list, t_list **list2);


#endif