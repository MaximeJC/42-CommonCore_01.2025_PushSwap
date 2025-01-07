/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:29:48 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 13:10:19 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	char	**args;
	int		i;

	i = 1;
	if (argc == 1)
		return 0;
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = ft_calloc(argc - 1, sizeof(char *));
		if (args == NULL)
			exit(EXIT_FAILURE);
		while (i++ < argc)
		{
			args[i - 2] = ft_strdup(argv[i]);
			if (args[i - 2] == NULL)
			{
				while (i-- > 1)
					free(args[i - 1]);
				exit(EXIT_FAILURE);
			}
		}
	}
	return 0;
}
