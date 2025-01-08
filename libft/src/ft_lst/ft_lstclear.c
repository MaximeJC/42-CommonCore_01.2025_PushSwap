/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:42 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 11:19:54 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*lst_el;
	t_list	*lst_next_el;

	lst_next_el = *lst;
	while (lst_next_el != NULL)
	{
		lst_el = lst_next_el;
		lst_next_el = lst_el->next;
		free(lst_el);
	}
	*lst = NULL;
}
