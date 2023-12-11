/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:39 by vopekdas          #+#    #+#             */
/*   Updated: 2023/12/09 17:28:30 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "push_swap.h"

int	ft_check_not_int(int argc, char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_bigger_than_int(int argc, char **str)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(str[i]) < 0 && ft_strlen(str[i]) > 11)
			return (1);
		if (ft_atoi(str[i]) > 0 && ft_strlen(str[i]) > 10)
			return (1);
		if ((ft_atoi(str[i]) > INT_MAX) || ((ft_atoi(str[i]) < INT_MIN)))
			return (1);
		i++;
	}
	return (0);
}

// int	main (int argc, char **argv) {

// 	ft_printf("%d\n", ft_check_bigger_than_int(argc, argv));
// 	return 0;
// }