/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:03:07 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 10:06:44 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_content_del(void *content)
{
	free(content);
}

void	ft_clearstack(t_list *stack)
{
	void	(*del)(void*) = lst_content_del;

	ft_lstclear(&stack, del);
}

int	*data_init(int nb)
{
	int	nbr;
	int	*p_nbr;

	nbr = nb;
	p_nbr = &nbr;
	return (p_nbr);
}
