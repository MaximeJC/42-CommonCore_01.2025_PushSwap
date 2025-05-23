#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp_el;

	temp_el = NULL;
	if (*lst != NULL && (*lst)->next != NULL)
	{
		temp_el = (*lst)->next->next;
		ft_lstadd_front(lst, (*lst)->next);
		(*lst)->next->next = temp_el;
	}
	return ;
}

void	sa(t_list **a, int print)
{
	if (print)
		ft_printf("sa\n");
	swap(a);
	return ;
}

void	sb(t_list **b, int print)
{
	if (print)
		ft_printf("sb\n");
	swap(b);
	return ;
}

void	ss(t_list **a, t_list **b, int print)
{
	if (print)
		ft_printf("ss\n");
	swap(a);
	swap(b);
	return ;
}
