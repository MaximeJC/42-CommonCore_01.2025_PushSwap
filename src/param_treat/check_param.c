/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:43:00 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 17:12:28 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(char	*str);
static int	*data_init(int nb);

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

void	argstostack(char **args, t_list *a)
{
	int		i;
	int		error;
	long	nbr;
	t_list	*el;
	t_list	*new_el;
	void	(*del)(void*) = lst_content_del;

	i = 0;
	error = 0;
	nbr = 0;
	el = NULL;
	new_el = NULL;
	while (args[i] != NULL && error == 0)
	{
		error = check_str(args[i]);
		if (error == 0)
			nbr = ft_atol(args[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error = 1;
		if (i == 0 && error == 0)
		{
			a = ft_lstnew(data_init(nbr));
			if (a == NULL)
				error = 1;
			el = a;
		}
		else if (error == 0)
		{
			new_el = ft_lstnew(data_init(nbr));
			if (new_el == NULL)
			{
				error = 1;
			}
			else
			{
				el->next = new_el;
				el = new_el;
			}
		}
		free(args[i]);
		i++;
	}
	while (error == 1 && args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	if (error == 1)
	{
		ft_lstclear(&a, del);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	//! Check doubles
}

static int	*data_init(int nb)
{
	int	nbr;
	int	*p_nbr;

	nbr = nb;
	p_nbr = &nbr;
	return (p_nbr);
}

int	check_str(char	*str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
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

// int	check_double(t_list *a)
// {
// 	return (0);
// }
