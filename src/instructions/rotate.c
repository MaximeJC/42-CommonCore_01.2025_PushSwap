/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:48 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 16:34:19 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*temp_el;

	temp_el = (*lst);
	if ((*lst) != NULL && (*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		temp_el->next = NULL;
		ft_lstadd_back(lst, temp_el);
	}
	return ;
}

void	ra(t_list **a)
{
	ft_printf("ra\n");
	rotate(a);
	return ;
}

void	rb(t_list **b)
{
	ft_printf("rb\n");
	rotate(b);
	return ;
}

void	rr(t_list **a, t_list **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
	return ;
}
