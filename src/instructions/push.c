/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:42 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/20 14:58:59 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
