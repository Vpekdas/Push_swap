/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/09 15:10:41 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"

void	ft_instruction_pa(t_list **list, t_list **list2);
void	ft_instruction_pb(t_list **list, t_list **list2);
void	ft_instruction_rra(t_list **list);
void	ft_instruction_rrb(t_list **list);
void	ft_instruction_rrr(t_list **list, t_list **list2);
void	ft_instruction_ra(t_list **list);
void	ft_instruction_rb(t_list **list);
void	ft_instruction_rr(t_list **list, t_list **list2);
void	ft_instruction_sa(t_list **list);
void	ft_instruction_sb(t_list **list);
void	ft_instruction_ss(t_list **list, t_list **list2);
t_list	*ft_linked_list(int argc, char **argv);
int	ft_check_not_int(int argc, char **argv);
int	ft_check_bigger_than_int(int argc, char **argv);
int	ft_check_is_not_duplicate(int argc, char **argv);


#endif