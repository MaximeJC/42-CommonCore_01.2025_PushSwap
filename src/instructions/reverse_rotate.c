#include "push_swap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*temp_el;

	temp_el = NULL;
	if ((*lst) != NULL && (*lst)->next != NULL)
	{
		temp_el = ft_lstlast(*lst);
		ft_lstsecondtolast(*lst)->next = NULL;
		ft_lstadd_front(lst, temp_el);
	}
	return ;
}

void	rra(t_list **a, int print)
{
	if (print)
		ft_printf("rra\n");
	reverse_rotate(a);
	return ;
}

void	rrb(t_list **b, int print)
{
	if (print)
		ft_printf("rrb\n");
	reverse_rotate(b);
	return ;
}

void	rrr(t_list **a, t_list **b, int print)
{
	if (print)
		ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
	return ;
}
