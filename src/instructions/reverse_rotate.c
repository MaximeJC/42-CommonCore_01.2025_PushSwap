/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:40 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 15:24:04 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list *el)
{
	return ;
}

void	rra(t_list *a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
	return ;
}

void	rrb(t_list *b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
	return ;
}

void	rrr(t_list *a, t_list *b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
	return ;
}
