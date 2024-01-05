/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/05 17:21:09 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"

void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **b, t_list **a);

void	ft_ra(t_list **list, int t);
void	ft_rb(t_list **list, int t);
void	ft_rr(t_list **list, t_list **list2);

void	ft_rra(t_list **list, int t);
void	ft_rrb(t_list **list, int t);
void	ft_rrr(t_list **list, t_list **list2);

void	ft_sa(t_list **list, int t);
void	ft_sb(t_list **list, int t);
void	ft_ss(t_list **list, t_list **list2);

int		ft_check_not_int(int ac, char **av);
int		ft_check_over_under_int(int ac, char **av);
int		ft_check_is_not_duplicate(int ac, char **av);
int		ft_check_sorted(t_list	*a);
int		ft_overall_check(int ac, char **av);
int		ft_check_not_int_split(int ac, char **av);
int		ft_check_over_under_int_split(int ac, char **av);
int		ft_check_is_not_duplicate_split(int ac, char **av);
int		ft_check_sorted_split(t_list	*a);
int		ft_overall_check_split(int ac, char **av);

int		ft_find_biggest(t_list *a);
int		ft_find_smaller(t_list *a);
int		ft_num_pos(t_list *a, int num);
int		ft_find_right_pos(t_list *a, int c);
int		ft_find_right_pos2(t_list *a, int c);
int		ft_strcmp(char *s1, char *s2);

t_list	*ft_linked_list(int ac, char **av);
t_list	*ft_linked_list_split(int ac, char **av);
int		ft_count_words(char **str);
void	ft_free_split(char **str);
void	ft_free_list(t_list **a, t_list **b);

int		ft_which_move_a(t_list *a, t_list *b);
int		ft_case_ra_rb(t_list *a, t_list *b, int c);
int		ft_case_rra_rb(t_list	*a, t_list *b, int c);
int		ft_case_rra_rrb(t_list *a, t_list *b, int c);
int		ft_case_ra_rrb(t_list *a, t_list *b, int c);

int		ft_which_move_b(t_list *a, t_list *b);
int		ft_case_ra_rb2(t_list *a, t_list *b, int c);
int		ft_case_rra_rb2(t_list	*a, t_list *b, int c);
int		ft_case_rra_rrb2(t_list *a, t_list *b, int c);
int		ft_case_ra_rrb2(t_list *a, t_list *b, int c);

int		ft_apply_ra_rb(t_list **a, t_list **b, int c);
int		ft_apply_ra_rrb(t_list **a, t_list **b, int c);
int		ft_apply_rra_rrb(t_list **a, t_list **b, int c);
int		ft_apply_rra_rb(t_list **a, t_list **b, int c);

int		ft_apply_ra_rb2(t_list **a, t_list **b, int c);
int		ft_apply_rra_rb2(t_list **a, t_list **b, int c);
int		ft_apply_rra_rrb2(t_list **a, t_list **b, int c);
int		ft_apply_ra_rrb2(t_list **a, t_list **b, int c);

void	ft_sort_two(t_list **a);
void	ft_sort_three(t_list **a);
void	ft_sort_till_3_remains(t_list **a, t_list **b);
void	ft_sort_till_empty(t_list **a, t_list **b);
void	ft_sort_opti(t_list **a, t_list **b);
void	ft_sort_list(t_list **a, t_list **b);

#endif 