/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/15 16:26:20 by vopekdas         ###   ########.fr       */
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
void	ft_ra_multiple(t_list **a, int pos);
void	ft_rra_multiple(t_list **a, int pos);
int		ft_find_biggest(t_list **a);
int		ft_find_smaller(t_list **a);
void	ft_rotate_multiple(t_list **a, int pos);
int		ft_num_pos(t_list **a, int num);
int		ft_find_right_pos(t_list **a, int c);
int		ft_check_sorted(t_list	**a);
void	ft_sort_five(t_list	**a, t_list	**b);
void	ft_sort_till_3_remains(t_list **a, t_list **b);
int		ft_num_pos(t_list **a, int num);

#endif