/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:49 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/14 15:47:23 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_element	get_cheaper(t_list *a, t_list *b);

void	sort(t_list **a, t_list **b)
{
	t_element	el;
	int			i;

	i = 3;
	pb(a, b);
	if (ft_lstsize(*a) != 3)
	{
		pb(a, b);
		if ((*b)->content < (*b)->next->content)
			sb(b);
	}
	while (ft_lstsize(*a) != 3)
	{
		el = get_cheaper(*a, *b);
		exec_sort(a, b, el);
	}
	sort_three(a);
	while ((*b)->content < ft_lstlast(*b)->content)
		rrb(b);
	while (ft_lstsize(*b) != 0)
	{
		if ((*b)->content > ft_lstlast(*a)->content || i == 0)
			pa(a, b);
		else
		{
			rra(a);
			i--;
		}
	}
	while ((*a)->content > ft_lstlast(*a)->content)
		rra(a);
}

static t_element	get_cheaper(t_list *a, t_list *b)
{
	t_element	cheap_el;
	t_element	test_el;
	t_list		*el;

	cheap_el.cost = INT_MAX;
	el = a;
	test_el.content = el->content;
	while (el != NULL)
	{
		// get content
		test_el.content = el->content;
		// Get rot_a
		test_el.rot_a = getnbrot_a(a, test_el.content);
		// get rrot_a
		test_el.rrot_a = ft_lstsize(a) - test_el.rot_a;
		// get rot_b
		test_el.rot_b = getnbrot_b(b, test_el.content, 0, INT_MIN);
		// get rrot_b
		test_el.rrot_b = ft_lstsize(b) - test_el.rot_b;
		// calc cost
		test_el.cost = getcost(test_el);
		// compare and replace cheap_el
		if (test_el.cost < cheap_el.cost)
			cheap_el = test_el;
		// get next test_el
		el = el->next;
	}
	return cheap_el;
}


