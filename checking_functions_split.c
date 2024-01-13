/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions_split.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:52 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/13 15:42:26 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		j;
	char	*str;
	char	*arg;

	i = 0;
	j = 0;
	while (i < ac)
	{
		str = ft_itoa(ft_atoi(av[i]));
		arg = av[i];
		if (*arg == '-' && str[j++] == '-')
			arg++;
		while (*arg && *arg == '0' && ft_strlen(arg) > 1)
			arg++;
		j += ft_skip_zero(str);
		if (ft_strcmp(arg, str + j) != 0)
			return (free(str), 1);
		free(str);
		j = 0;
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

int	ft_check_sorted_split(t_list *a)
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
