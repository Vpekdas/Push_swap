/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:19 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/09 14:23:28 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"

# define PRINT 1
# define NO_PRINT 0

void	ft_pa(t_list **a, t_list **b, int p);
void	ft_pb(t_list **b, t_list **a, int p);

void	ft_rra(t_list **a, int p);
void	ft_rrb(t_list **b, int p);
void	ft_rrr(t_list **a, t_list **b, int p);

void	ft_ra(t_list **a, int p);
void	ft_rb(t_list **b, int p);
void	ft_rr(t_list **a, t_list **b, int p);

void	ft_sa(t_list **a, int p);
void	ft_sb(t_list **b, int p);
void	ft_ss(t_list **a, t_list **b, int p);

t_list	*ft_linked_list(int ac, char **av);
t_list	*ft_linked_list_split(int ac, char **av);
t_list	*ft_linked_list_if_ac_2(char **av);

int		ft_free_split(char **str);
int		ft_free_list(t_list **a, t_list **b);
t_list	*ft_free_split_and_print_error(char **str);

int		ft_print_error(void);
int		ft_check_not_int(int ac, char **av);
int		ft_check_over_under_int(int ac, char **av);
int		ft_check_is_not_duplicate(int ac, char **av);
int		ft_check_sorted(t_list *a);
int		ft_overall_check(int ac, char **av);
int		ft_check_not_int_split(int ac, char **av);
int		ft_check_over_under_int_split(int ac, char **av);
int		ft_check_is_not_duplicate_split(int ac, char **av);
int		ft_check_sorted_split(t_list *a);
int		ft_overall_check_split(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		ft_count_words(char **str);
int		ft_skip_zero_or_minus(char *str);

int		ft_find_biggest(t_list *a);
int		ft_find_smaller(t_list *a);
int		ft_num_pos(t_list *a, int num);
int		ft_find_right_pos(t_list *a, int c);
int		ft_find_right_pos2(t_list *a, int c);

int		ft_case_ra_rb(t_list *a, t_list *b, int c);
int		ft_case_rra_rb(t_list	*a, t_list *b, int c);
int		ft_case_rra_rrb(t_list *a, t_list *b, int c);
int		ft_case_ra_rrb(t_list *a, t_list *b, int c);
int		ft_which_move_b(t_list *a, t_list *b);

int		ft_case_ra_rb2(t_list *a, t_list *b, int c);
int		ft_case_rra_rb2(t_list	*a, t_list *b, int c);
int		ft_case_rra_rrb2(t_list *a, t_list *b, int c);
int		ft_case_ra_rrb2(t_list *a, t_list *b, int c);
int		ft_which_move_a(t_list *a, t_list *b);

int		ft_apply_ra_rb(t_list **a, t_list **b, int c);
int		ft_apply_ra_rrb(t_list **a, t_list **b, int c);
int		ft_apply_rra_rrb(t_list **a, t_list **b, int c);
int		ft_apply_rra_rb(t_list **a, t_list **b, int c);

int		ft_apply_ra_rb2(t_list **a, t_list **b, int c);
int		ft_apply_rra_rb2(t_list **a, t_list **b, int c);
int		ft_apply_rra_rrb2(t_list **a, t_list **b, int c);
int		ft_apply_ra_rrb2(t_list **a, t_list **b, int c);

void	ft_checker_sorted(t_list *a, t_list *b);
void	ft_checker_read2(t_list **a, t_list **b, char *line);
int		ft_gnl(char **line, int fd);
void	ft_checker_read(t_list **a, t_list **b);

void	ft_sort_two(t_list **a);
void	ft_sort_three(t_list **a);
void	ft_sort_four(t_list **a, t_list **b);
void	ft_sort_hundred_and_more(t_list **a, t_list **b);
void	ft_select_and_apply_sort(t_list **a, t_list **b);

void	ft_sort_till_3_remains(t_list **a, t_list **b);
void	ft_sort_till_empty(t_list **a, t_list **b);

#endif 