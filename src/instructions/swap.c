/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:46 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 16:06:18 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_list **a)
{
	ft_printf("sa\n");
	swap(a);
	return ;
}

void	sb(t_list **b)
{
	ft_printf("sb\n");
	swap(b);
	return ;
}

void	ss(t_list **a, t_list **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
	return ;
}
