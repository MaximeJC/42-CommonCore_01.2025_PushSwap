/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:51 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/13 15:07:11 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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

// Utils
int		is_sorted(t_list *lst);
int		is_rsorted(t_list *lst);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	rsort_three(t_list **b);

#endif
