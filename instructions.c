#include "push_swap.h"

void	sa_instruction(t_list *first_node, t_list *second_node)
{
	int	temp;

	temp = 0;
	if (!first_node || !second_node)
		return ;
	temp = first_node->content;
	first_node->content = second_node->content;
	second_node->content = temp;
	return ;
}
int	main() {
	t_list *node1 = ft_lstnew(1);
	t_list *node2 = ft_lstnew(2);

	node1->next = node2;
	ft_printf("BEFORE FUNCTION : %d -> %d -> null", node1->content, node2->content);
}