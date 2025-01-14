/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:44:21 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:00 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	int		highest;
	t_list	*el;

	el = lst;
	highest = el->content;
	while (el->next != NULL)
	{
		el = el->next;
		if (el->content > highest)
			highest = el->content;
		else
			return (0);
	}
	return (1);
}

int	is_rsorted(t_list *lst)
{
	int		lowest;
	t_list	*el;

	el = lst;
	lowest = el->content;
	while (el->next != NULL)
	{
		el = el->next;
		if (el->content < lowest)
			lowest = el->content;
		else
			return (0);
	}
	return (1);
}

void	sort_two(t_list **a)
{
	if (is_sorted(*a))
		return ;
	else
		sa(a);
	return ;
}

void	sort_three(t_list **a)
{
	if (is_sorted(*a))
		return ;
	else if (is_rsorted(*a) || ((*a)->content < (*a)->next->content
			&& (*a)->content < (*a)->next->next->content
			&& (*a)->next->content > (*a)->next->next->content))
		sa(a);
	if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		rra(a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		sa(a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ra(a);
	return ;
}
