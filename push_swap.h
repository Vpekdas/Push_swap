/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/12 17:03:57 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"

int		ft_check_not_int(int argc, char **argv);
int		ft_check_bigger_than_int(int argc, char **argv);
int		ft_check_is_not_duplicate(int argc, char **argv);
t_list	*ft_linked_list(int argc, char **argv);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **b, t_list **a);
void	ft_rra(t_list **list);
void	ft_rrb(t_list **list);
void	ft_rrr(t_list **list, t_list **list2);
void	ft_ra(t_list **list);
void	ft_rb(t_list **list);
void	ft_rr(t_list **list, t_list **list2);
void	ft_sa(t_list **list);
void	ft_sb(t_list **list);
void	ft_ss(t_list **list, t_list **list2);
void	ft_sort_three(t_list **list);
void	ft_sort_three(t_list **list);

#endif