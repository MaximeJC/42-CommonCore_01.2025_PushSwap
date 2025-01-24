/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:46:10 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/24 16:25:19 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	readinstructions(t_list **a, t_list **b);
static int	treatinstruction(t_list **a, t_list **b, char *instruction);

int	main(int argc, char *argv[])
{
	char	**args;
	t_list	*a;
	t_list	*b;

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
	readinstructions(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

static void	readinstructions(t_list **a, t_list **b)
{
	char	*instruction;

	instruction = NULL;
	while (1 == 1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		if (treatinstruction(a, b, instruction))
		{
			if (instruction != NULL)
			{
				ft_putstr_fd("Error\n", 2);
				free(instruction);
				ft_lstclear(a);
				ft_lstclear(b);
				exit(EXIT_FAILURE);
			}
			break ;
		}
		free(instruction);
	}
}

static int	treatinstruction(t_list **a, t_list **b, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(a, b, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(a, b, 0);
	else
		return (1);
	return (0);
}
