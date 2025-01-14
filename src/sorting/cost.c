/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:59 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/14 14:26:32 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		getlst_min(t_list *lst);
static t_list	*getlst_max(t_list *lst, int *b_max);

int	getnbrot_a(t_list *a, int content)
{
	t_list	*el;
	int		cost;

	el = a;
	cost = 0;
	while (el->content != content)
	{
		el = el->next;
		cost++;
	}
	return (cost);
}

int	getnbrot_b(t_list *b, int content, int cost, int b_max)
{
	int		b_content;
	int		b_min;
	t_list	*el;

	el = getlst_max(b, &b_max);
	b_min = getlst_min(b);
	if (content > b_max || content < b_min)
		b_content = b_max;
	else
	{
		while (el->content > content)
		{
			if (el->next == NULL)
				el = b;
			else
				el = el->next;
		}
		b_content = el->content;
	}
	while (el->content != b_content)
	{
		el = el->next;
		cost++;
	}
	return (cost);
}

int	getcost(t_element element)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_rarrb;
	int	cost_rrarb;

	cost_rarrb = element.rot_a + element.rrot_b;
	cost_rrarb = element.rrot_a + element.rot_b;
	cost_rr = ft_max(element.rot_a, element.rot_b);
	cost_rrr = ft_max(element.rrot_a, element.rrot_b);
	if (cost_rr <= cost_rrr && cost_rr <= cost_rarrb && cost_rr <= cost_rrarb)
		return (cost_rr);
	else if (cost_rrr <= cost_rr && cost_rrr <= cost_rarrb && cost_rrr <= cost_rrarb)
		return (cost_rrr);
	else if (cost_rarrb <= cost_rr && cost_rarrb <= cost_rrr && cost_rrr <= cost_rrarb)
		return (cost_rarrb);
	else
		return (cost_rrarb);
}

static int	getlst_min(t_list *lst)
{
	int		i;
	int		min;
	t_list	*el;

	i = 0;
	min = INT_MAX;
	el = lst;
	while (i != ft_lstsize(lst))
	{
		if (el->content < min)
			min = el->content;
		el = el->next;
		i++;
	}
	return (min);
}

static t_list	*getlst_max(t_list *lst, int *b_max)
{
	int		i;
	t_list	*el;
	t_list	*el_max;

	i = 0;
	el = lst;
	while (i != ft_lstsize(lst))
	{
		if (el->content > *b_max)
		{
			*b_max = el->content;
			el_max = el;
		}
		el = el->next;
		i++;
	}
	return (el_max);
}
