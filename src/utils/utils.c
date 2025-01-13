/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:44:21 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/13 13:55:35 by mgouraud         ###   ########.fr       */
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
