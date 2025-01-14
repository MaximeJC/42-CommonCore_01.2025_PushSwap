/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:46:10 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/14 18:26:04 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args;
	char	*instruction;
	t_list	*a;
	t_list	*b;

	args = NULL;
	instruction = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argvtoargs(argc, argv);
	argstostack(args, &a);
	// instruction = get_next_line(0);
	while (1 == 1)
	{
		instruction = get_next_line(0);
		ft_printf("-> %s", instruction);
		if (instruction == NULL)
			break;
		if (!ft_strncmp(instruction, "sa", 2))
			sa(&a);
		else if (!ft_strncmp(instruction, "sb", 2))
			sb(&b);
		else if (!ft_strncmp(instruction, "ss", 2))
			ss(&a, &b);
		else if (!ft_strncmp(instruction, "pa", 2))
			pa(&a, &b);
		else if (!ft_strncmp(instruction, "pb", 2))
			pb(&a, &b);
		else if (!ft_strncmp(instruction, "ra", 2))
			ra(&a);
		else if (!ft_strncmp(instruction, "rb", 2))
			rb(&b);
		else if (!ft_strncmp(instruction, "rr", 2))
			rr(&a, &b);
		else if (!ft_strncmp(instruction, "rra", 3))
			rra(&a);
		else if (!ft_strncmp(instruction, "rrb", 3))
			rrb(&b);
		else if (!ft_strncmp(instruction, "rrr", 3))
			rrr(&a, &b);
		else
			break;
	}
	if (is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
