/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:16:16 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/04 15:18:16 by vopekdas         ###   ########.fr       */
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
	t_list	*next;

	i = 1;
	next = a->next;
	if (c > a->content && c < ft_lstlast(a)->content)
		return (0);
	if (c > ft_find_biggest(a) || c < ft_find_smaller(a))
		return (ft_num_pos(a, ft_find_biggest(a)));
	while (a->content < c || next->content > c)
	{
		a = a->next;
		next = a->next;
		i++;
	}
	return (i);
}

