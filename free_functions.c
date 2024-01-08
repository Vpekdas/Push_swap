/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:03:06 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 16:03:57 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	ft_free_list(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
	}
	while (*b)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		free(tmp);
	}
	return (0);
}