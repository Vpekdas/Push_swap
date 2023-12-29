/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/29 15:19:10 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

void	ft_ra_multiple(t_list **a, int pos)
{
	while (pos > 0)
	{
		ft_ra(a);
		pos--;
	}
}

void	ft_rra_multiple(t_list **a, int pos)
{
	int	len;

	len = ft_lstsize(*a);
	pos = len - pos;
	while (pos > 0)
	{
		ft_rra(a);
		pos--;
	}
}

int	ft_find_biggest(t_list **a)
{
	int		num;
	t_list	*current;

	num = (*a)->content;
	current = (*a);
	while (current)
	{
		if (current->content > num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

int	ft_find_smaller(t_list **a)
{
	int		num;
	t_list	*current;

	num = (*a)->content;
	current = (*a);
	while (current)
	{
		if (current->content <= num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

void	ft_rotate_multiple(t_list **a, int pos)
{
	int	len;

	len = ft_lstsize(*a);
	if (pos < len / 2)
		(ft_ra_multiple(a, pos));
	else
		(ft_rra_multiple(a, pos));
}

int	ft_num_pos(t_list **a, int num)
{
	t_list	*current;
	int		pos;

	current = (*a);
	pos = 0;
	while (current)
	{
		if (current->content == num)
			return (pos);
		current = current->next;
		pos++;
	}
	return (pos);
}

int	ft_find_right_pos(t_list **a, t_list **b)
{
	int		pos;
	t_list	*tmp;
	int		smaller;
	int		biggest;

	smaller = ft_find_smaller(a);
	biggest = ft_find_biggest(a);
	tmp = (*a);
	if ((*b)->content < smaller)
		return (ft_num_pos(a, smaller));
	if ((*b)->content > biggest)
		return (ft_num_pos(a, biggest) + 1);
	pos = 1;
	while (tmp)
	{
		if ((*b)->content > tmp->content && (*b)->content < tmp->next->content)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	ft_check_sorted(t_list	**a)
{
	t_list	*current;

	current = (*a);
	while (current)
	{
		if (current->next)
		{
			if (current->content > current->next->content)
				return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_sort_five(t_list	**a, t_list	**b)
{
	int	pos;
	int	smaller;

	pos = 0;
	smaller = 0;
	ft_pb(a, b);
	ft_pb(a, b);
	ft_sort_three(a);
	pos = ft_find_right_pos(a, b);
	ft_rotate_multiple(a, pos);
	ft_pa(b, a);
	pos = ft_find_right_pos(a, b);
	ft_rotate_multiple(a, pos);
	ft_pa(b, a);
	if (ft_check_sorted(a))
	{
		smaller = ft_find_smaller(a);
		pos = ft_num_pos(a, smaller);
		ft_rotate_multiple(a, pos);
	}
}

// int	main (int argc, char **argv)
// {
// 	t_list	*list = ft_linked_list(argc, argv);
// 	t_list	*list2 = NULL;
// 	t_list	*current = list;

// 	ft_printf("BEFORE SORTING\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	ft_sort_five(&list, &list2);

// 	current = list;

// 	ft_printf("AFTER SORTING IN STACK A\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);

// 	current = list2;

// 	ft_printf("AFTER SORTING IN STACK B\n");
// 	ft_printf("==================\n");
// 	while (current)
// 	{
// 		ft_printf("%d -> ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("%s\n", current);
// }