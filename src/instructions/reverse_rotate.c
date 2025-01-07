/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:40 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 13:46:50 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list *el)
{
	return ;
}

void	rra(t_list *a)
{
	reverse_rotate(a);
	return ;
}

void	rrb(t_list *b)
{
	reverse_rotate(b);
	return ;
}

void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
	return ;
}
