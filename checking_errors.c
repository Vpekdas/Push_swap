/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:39 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/04 14:56:19 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

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


int	ft_check_over_under_int(int argc, char **argv)
{
	int		i;
	int		res;
	char	*str;
	char 	*arg;

    i = 1;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		str = ft_itoa(res);

		ft_printf("res: %d\n", res);
		ft_printf("str: %s\n", str);
		arg = argv[i];
		if (*arg == '-')
			arg++;
		while (*arg && *arg == '0')
			arg++;
		if (ft_strcmp(arg, str + (*str == '-')) != 0)
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
