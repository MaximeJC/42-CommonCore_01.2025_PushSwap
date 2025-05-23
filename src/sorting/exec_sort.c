#include "push_swap.h"

static void	exec_rr(t_list **a, t_list **b, t_element element);
static void	exec_rrr(t_list **a, t_list **b, t_element element);
static void	exec_rarrb(t_list **a, t_list **b, t_element element);
static void	exec_rrarb(t_list **a, t_list **b, t_element element);

void	exec_sort(t_list **a, t_list **b, t_element element)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_rarrb;
	int	cost_rrarb;

	cost_rarrb = element.rot_a + element.rrot_b;
	cost_rrarb = element.rrot_a + element.rot_b;
	cost_rr = ft_max(element.rot_a, element.rot_b);
	cost_rrr = ft_max(element.rrot_a, element.rrot_b);
	if (cost_rr <= cost_rrr && cost_rr <= cost_rarrb && cost_rr <= cost_rrarb)
		exec_rr(a, b, element);
	else if (cost_rrr <= cost_rr && cost_rrr <= cost_rarrb
		&& cost_rrr <= cost_rrarb)
		exec_rrr(a, b, element);
	else if (cost_rarrb <= cost_rr && cost_rarrb <= cost_rrr
		&& cost_rrr <= cost_rrarb)
		exec_rarrb(a, b, element);
	else
		exec_rrarb(a, b, element);
	pb(a, b, 1);
}

static void	exec_rr(t_list **a, t_list **b, t_element element)
{
	while (element.rot_a > 0 && element.rot_b > 0)
	{
		rr(a, b, 1);
		element.rot_a--;
		element.rot_b--;
	}
	while (element.rot_a > 0)
	{
		ra(a, 1);
		element.rot_a--;
	}
	while (element.rot_b > 0)
	{
		rb(b, 1);
		element.rot_b--;
	}
}

static void	exec_rrr(t_list **a, t_list **b, t_element element)
{
	while (element.rrot_a > 0 && element.rrot_b > 0)
	{
		rrr(a, b, 1);
		element.rrot_a--;
		element.rrot_b--;
	}
	while (element.rrot_a > 0)
	{
		rra(a, 1);
		element.rrot_a--;
	}
	while (element.rrot_b > 0)
	{
		rrb(b, 1);
		element.rrot_b--;
	}
}

static void	exec_rarrb(t_list **a, t_list **b, t_element element)
{
	while (element.rot_a > 0)
	{
		ra(a, 1);
		element.rot_a--;
	}
	while (element.rrot_b > 0)
	{
		rrb(b, 1);
		element.rrot_b--;
	}
}

static void	exec_rrarb(t_list **a, t_list **b, t_element element)
{
	while (element.rrot_a > 0)
	{
		rra(a, 1);
		element.rrot_a--;
	}
	while (element.rot_b > 0)
	{
		rb(b, 1);
		element.rot_b--;
	}
}
