/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:43:00 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 14:31:45 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		args[i - 2] = ft_strdup(argv[i]);
		if (args[i - 2] == NULL)
		{
			while (i-- > 1)
				free(args[i - 1]);
			free(args);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
	args[i - 1] = NULL;
	return (args);
}
