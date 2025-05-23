/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:44:21 by mgouraud          #+#    #+#             */
/*   Updated: 2025/05/24 01:01:54 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	int		highest;
	t_list	*el;

	el = lst;
	highest = *(int *)el->content;
	while (el->next != NULL)
	{
		el = el->next;
		if (*(int *)el->content > highest)
			highest = *(int *)el->content;
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
	lowest = *(int *)el->content;
	while (el->next != NULL)
	{
		el = el->next;
		if (*(int *)el->content < lowest)
			lowest = *(int *)el->content;
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
		sa(a, 1);
	return ;
}

void	sort_three(t_list **a)
{
	if (is_sorted(*a))
		return ;
	else if (is_rsorted(*a)
		|| (*(int *)(*a)->content < *(int *)(*a)->next->content
			&& *(int *)(*a)->content < *(int *)(*a)->next->next->content
			&& *(int *)(*a)->next->content > *(int *)(*a)->next->next->content))
		sa(a, 1);
	if (*(int *)(*a)->content < *(int *)(*a)->next->content
		&& *(int *)(*a)->content > *(int *)(*a)->next->next->content
		&& *(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
		rra(a, 1);
	else if (*(int *)(*a)->content > *(int *)(*a)->next->content
		&& *(int *)(*a)->content < *(int *)(*a)->next->next->content
		&& *(int *)(*a)->next->content < *(int *)(*a)->next->next->content)
		sa(a, 1);
	else if (*(int *)(*a)->content > *(int *)(*a)->next->content
		&& *(int *)(*a)->content > *(int *)(*a)->next->next->content
		&& *(int *)(*a)->next->content < *(int *)(*a)->next->next->content)
		ra(a, 1);
	return ;
}
