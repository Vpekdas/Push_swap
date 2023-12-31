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

int	ft_find_biggest(t_list *a)
{
	int		num;
	t_list	*current;

	current = a;
	num = current->content;
	while (current)
	{
		if (current->content > num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

int	ft_find_smaller(t_list *a)
{
	int		num;
	t_list	*current;

	current = a;
	num = current->content;
	while (current)
	{
		if (current->content < num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

int	ft_num_pos(t_list *a, int num)
{
	t_list	*current;
	int		pos;

	current = a;
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

int	ft_find_right_pos(t_list *a, int c)
{
	t_list	*current;
	int		pos;
	int		smaller;
	int		biggest;
	int		last_c;


	current = a;
	pos = 1;
	smaller = ft_find_smaller(a);
	biggest = ft_find_biggest(a);
	last_c = ft_lstlast(a)->content;

	if (c > a->content && c < last_c)
		return (pos);
	if (c > biggest || c < smaller)
		return (ft_num_pos(a, biggest));
	while (current)
	{
		if (current->next && c > current->content && c < current->next->content)
			return (pos);
		current = current->next;
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
