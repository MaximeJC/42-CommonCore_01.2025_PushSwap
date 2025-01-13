/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:49 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/13 17:39:49 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	int	i;

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
		//TODO : Calc cost + apply it
	}
	sort_three(a);
	while (ft_lstsize(*b) != 0)
	{
		// Can be optimized (+3 cps): check if all values in B (if Max B)
		// are smaller than (*a)->content qui est le plus petit de A
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
