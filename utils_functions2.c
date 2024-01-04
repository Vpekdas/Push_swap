/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:18:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/04 15:26:06 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_find_right_pos2(t_list *a, int c)
{
	int		i;
	t_list	*next;

	i = 1;
	next = a->next;
	if (c < a->content && c > ft_lstlast(a)->content)
		return (0);
	if (c > ft_find_biggest(a) || c < ft_find_smaller(a))
		return (ft_num_pos(a, ft_find_smaller(a)));
	while (a->content > c || next->content < c)
	{
		a = a->next;
		next = a->next;
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
