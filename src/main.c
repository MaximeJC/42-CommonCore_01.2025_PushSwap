/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:29:48 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/08 17:21:37 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args;
	t_list	*a;
	t_list	*b;
	t_list	*el = NULL;	//! To delete

	args = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argvtoargs(argc, argv);
	argstostack(args, &a);

	//! To delete
	ft_printf("[A]: ");
	el = a;
	if (el != NULL)
	{
		while (el->next != NULL)
		{
			ft_printf("%d ", el->content);
			el = el->next;
		}
		ft_printf("%d\n", el->content);
		el = NULL;
	}
	else
		ft_printf("NULL\n");
	ft_printf("[B]: ");
	el = b;
	if (el != NULL)
	{
		while (el->next != NULL)
		{
			ft_printf("%d ", el->content);
			el = el->next;
		}
		ft_printf("%d\n", el->content);
		el = NULL;
	}
	else
		ft_printf("NULL\n");
	//! To delete

	//TODO Tri des elements

	//! To delete
	ft_printf("[A]: ");
	el = a;
	if (el != NULL)
	{
		while (el->next != NULL)
		{
			ft_printf("%d ", el->content);
			el = el->next;
		}
		ft_printf("%d\n", el->content);
		el = NULL;
	}
	else
		ft_printf("NULL\n");
	ft_printf("[B]: ");
	el = b;
	if (el != NULL)
	{
		while (el->next != NULL)
		{
			ft_printf("%d ", el->content);
			el = el->next;
		}
		ft_printf("%d\n", el->content);
		el = NULL;
	}
	else
		ft_printf("NULL\n");
	//! To delete

	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
