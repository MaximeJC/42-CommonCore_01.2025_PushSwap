/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:51 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/14 11:45:49 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_element
{
	int	content;
	int	cost;
	int	rot_a;
	int	rot_b;
	int	rrot_a;
	int	rrot_b;
}	t_element;

// Param_treat
char	**argvtoargs(int argc, char *argv[]);
void	argstostack(char **args, t_list **a);

// Instructions
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// Sorting
void	sort(t_list **a, t_list **b);

// Utils
int		is_sorted(t_list *lst);
int		is_rsorted(t_list *lst);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	rsort_three(t_list **b);

#endif
