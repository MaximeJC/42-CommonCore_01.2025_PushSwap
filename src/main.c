/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:29:48 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 17:20:14 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_clearstacks(t_list *a, t_list *b);

int	main(int argc, char *argv[])
{
	char	**args;
	t_list	a;
	t_list	b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argvtoargs(argc, argv);
	argstostack(args, &a);


	ft_clearstacks(&a, &b);
	return (0);
}

static void	ft_clearstacks(t_list *a, t_list *b)
{
	void	(*del)(void*) = lst_content_del;

	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
}
