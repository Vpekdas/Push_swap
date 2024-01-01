/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/01 16:01:56 by vopekdas         ###   ########.fr       */
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
	int		i;
	t_list	*tmp;

	i = 1;
	if (c > a->content && c < ft_lstlast(a)->content)
		i = 0;
	else if (c > ft_find_biggest(a) || c < ft_find_smaller(a))
		i = ft_num_pos(a, ft_find_biggest(a));
	else
	{
		tmp = a->next;
		while (a->content < c || tmp->content > c)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
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
