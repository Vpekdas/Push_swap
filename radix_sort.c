#include "push_swap.h"
#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"

int	ft_putnbr_base_sort(unsigned int nb, char *base)
{
	long long		i;
	char			result [100];
	int				len;

	if (nb == 0)
		return (1);
	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	len = i;
	return (len);
}

int	ft_get_max_digit_bit(t_list **a)
{
	int		max;
	int		digit_count;
	t_list	*current;

	max = (*a)->content;
	current = *a;
	digit_count = 0;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	digit_count = ft_putnbr_base_sort(max, "01");
	return (digit_count);
}

void	ft_radix_sort(t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		digit_count;
	t_list	*current;
	int		list_size;

	i = 0;
	digit_count = ft_get_max_digit_bit(a);
	list_size = ft_lstsize(*a);
	while (i < digit_count)
	{
		j = 0;
		while (j < list_size)
		{
			current = *a;
			if ((current->content >> i) & 1)
				ft_ra(a);
			else
				ft_pa(a, b);
			j++;
		}
		while (*b)
			ft_pb(b, a);
		i++;
	}
}
int	main (int argc, char **argv)
{
	t_list	*list = ft_linked_list(argc, argv);
	t_list	*list2 = NULL;
	t_list	*current = list;

	ft_printf("BEFORE SORTING\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

	ft_radix_sort(&list, &list2);

	current = list;

	ft_printf("AFTER SORTING IN STACK A\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);

	current = list2;

	ft_printf("AFTER SORTING IN STACK B\n");
	ft_printf("==================\n");
	while (current)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%s\n", current);
}
