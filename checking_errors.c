/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:39 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/03 15:22:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_check_not_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

// TODO handle -0000000001

int	ft_check_over_under_int(int argc, char **argv)
{
	int		i;
	int		res;
	char	*str;

	i = 1;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		str = ft_itoa(res);
		ft_printf("res: %d\n", res);
		ft_printf("str: %s\n", str);
		while (*argv[i] && *argv[i] == '0')
			argv[i]++;
		if (ft_strcmp(argv[i], str) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_is_not_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	main (int ac, char **av)
{
	ft_printf("check_not_int: %d\n", ft_check_over_under_int(ac, av));
}