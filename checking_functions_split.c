/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions_split.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:52 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/06 17:48:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"
#include <stdlib.h>

int	ft_check_not_int_split(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_over_under_int_split(int ac, char **av)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	while (i < ac)
	{
		res = ft_atoi(av[i]);
		str = ft_itoa(res);
		if (ft_strcmp(av[i], str) != 0)
		{
			free(str);
			return (1);
		}
		free(str);
		i++;
	}
	return (0);
}

int	ft_check_is_not_duplicate_split(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_sorted_split(t_list	*a)
{
	t_list	*current;

	current = a;
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

int	ft_overall_check_split(int ac, char **av)
{
	if (ft_check_not_int_split(ac, av))
		return (1);
	if (ft_check_over_under_int_split(ac, av))
		return (1);
	if (ft_check_is_not_duplicate_split(ac, av))
		return (1);
	return (0);
}
