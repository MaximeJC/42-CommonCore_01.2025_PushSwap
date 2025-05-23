/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:49 by mgouraud          #+#    #+#             */
/*   Updated: 2025/05/24 01:02:40 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_element	get_cheaper(t_list *a, t_list *b);
static void			push_back(t_list **a, t_list **b);
static int			getlst_maxpos(t_list *lst);

void	sort(t_list **a, t_list **b)
{
	t_element	el;

	pb(a, b, 1);
	if (ft_lstsize(*a) != 3)
	{
		pb(a, b, 1);
		if (*(int *)(*b)->content < *(int *)(*b)->next->content)
			sb(b, 1);
	}
	while (ft_lstsize(*a) != 3)
	{
		el = get_cheaper(*a, *b);
		exec_sort(a, b, el);
	}
	sort_three(a);
	push_back(a, b);
}

static void	push_back(t_list **a, t_list **b)
{
	int	i;

	i = 3;
	if (getlst_maxpos(*b) <= ft_lstsize(*b) / 2)
	{
		while (*(int *)(*b)->content < *(int *)ft_lstlast(*b)->content)
			rb(b, 1);
	}
	else
	{
		while (*(int *)(*b)->content < *(int *)ft_lstlast(*b)->content)
			rrb(b, 1);
	}
	while (ft_lstsize(*b) != 0)
	{
		if (*(int *)(*b)->content > *(int *)ft_lstlast(*a)->content || i == 0)
			pa(a, b, 1);
		else
		{
			rra(a, 1);
			i--;
		}
	}
	while (*(int *)(*a)->content > *(int *)ft_lstlast(*a)->content)
		rra(a, 1);
}

static t_element	get_cheaper(t_list *a, t_list *b)
{
	t_element	cheap_el;
	t_element	test_el;
	t_list		*el;

	cheap_el.cost = INT_MAX;
	el = a;
	test_el.content = *(int *)el->content;
	while (el != NULL)
	{
		test_el.content = *(int *)el->content;
		test_el.rot_a = getnbrot_a(a, test_el.content);
		test_el.rrot_a = ft_lstsize(a) - test_el.rot_a;
		if (test_el.rot_a + 1 < cheap_el.cost
			|| test_el.rrot_a + 1 < cheap_el.cost)
		{
			test_el.rot_b = getnbrot_b(b, test_el.content, 0, INT_MIN);
			test_el.rrot_b = ft_lstsize(b) - test_el.rot_b;
			test_el.cost = getcost(test_el);
			if (test_el.cost < cheap_el.cost)
				cheap_el = test_el;
		}
		el = el->next;
	}
	return (cheap_el);
}

static int	getlst_maxpos(t_list *lst)
{
	int		i;
	int		count;
	int		b_max;
	t_list	*el;

	i = 0;
	count = 1;
	b_max = INT_MIN;
	el = lst;
	while (i != ft_lstsize(lst))
	{
		if (*(int *)el->content > b_max)
			b_max = *(int *)el->content;
		el = el->next;
		i++;
	}
	el = lst;
	while (el != NULL && *(int *)el->content != b_max)
	{
		count++;
		el = el->next;
	}
	return (count);
}
