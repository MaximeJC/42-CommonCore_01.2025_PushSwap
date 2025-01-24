/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:43:00 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/24 16:20:34 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argstostack_sub(char **args, t_list **a, int i, t_list **el);
static int	check_str(char	*str);
static int	check_double(t_list *a);

char	**argvtoargs(int argc, char *argv[])
{
	char	**args;
	int		i;

	i = 1;
	args = ft_calloc(argc, sizeof(char *));
	if (args == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	while (i++ < argc)
	{
		args[i - 2] = ft_strdup(argv[i - 1]);
		if (args[i - 2] == NULL)
		{
			while (i-- > 1)
				free(args[i - 1]);
			free(args);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
	args[i - 2] = NULL;
	return (args);
}

void	argstostack(char **args, t_list **a)
{
	int		i;
	int		error;
	t_list	*el;

	i = 0;
	error = 0;
	el = NULL;
	if (args[i] == NULL)
		error = 1;
	while (args[i] != NULL && error == 0)
	{
		error = argstostack_sub(args, a, i, &el);
		free(args[i++]);
	}
	while (error == 1 && args[i] != NULL)
		free(args[i++]);
	free(args);
	if (error == 0)
		error = check_double(*a);
	if (error == 1)
	{
		ft_lstclear(a);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}

static int	argstostack_sub(char **args, t_list **a, int i, t_list **el)
{
	long	nbr;
	t_list	*new_el;

	nbr = 0;
	new_el = NULL;
	nbr = ft_atol(args[i]);
	if (check_str(args[i]) == 1 || nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	if (i == 0)
	{
		*a = ft_lstnew((int)nbr);
		if (*a == NULL)
			return (1);
		*el = *a;
	}
	else
	{
		new_el = ft_lstnew((int)nbr);
		if (new_el == NULL)
			return (1);
		(*el)->next = new_el;
		*el = (*el)->next;
	}
	return (0);
}

static int	check_str(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		i++;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

static int	check_double(t_list *a)
{
	t_list	*ref_el;
	t_list	*el;

	ref_el = a;
	el = NULL;
	while (ref_el->next != NULL)
	{
		el = ref_el->next;
		while (el != NULL)
		{
			if (ref_el->content == el->content)
				return (1);
			el = el->next;
		}
		ref_el = ref_el-> next;
	}
	return (0);
}
