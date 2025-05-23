#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*temp_el;

	temp_el = NULL;
	if ((*from) != NULL)
	{
		temp_el = (*from);
		(*from) = (*from)->next;
		ft_lstadd_front(to, temp_el);
	}
	return ;
}

void	pa(t_list **a, t_list **b, int print)
{
	if (print)
		ft_printf("pa\n");
	push(b, a);
	return ;
}

void	pb(t_list **a, t_list **b, int print)
{
	if (print)
		ft_printf("pb\n");
	push(a, b);
	return ;
}
