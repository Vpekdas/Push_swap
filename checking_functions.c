/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:39 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/08 11:57:00 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_not_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
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

int	ft_check_over_under_int(int ac, char **av)
{
	int		i;
	int		res;
	char	*str;

	i = 1;
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

int	ft_check_is_not_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
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

int	ft_check_sorted(t_list	*a)
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

int	ft_overall_check(int ac, char **av)
{
	if (ft_check_not_int(ac, av))
		return (1);
	if (ft_check_over_under_int(ac, av))
		return (1);
	if (ft_check_is_not_duplicate(ac, av))
		return (1);
	return (0);
}
