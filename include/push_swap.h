/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:51 by mgouraud          #+#    #+#             */
/*   Updated: 2025/01/07 17:26:55 by mgouraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	lst_content_del(void *content)
{
	free(content);
}

char	**argvtoargs(int argc, char *argv[]);
void	argstostack(char **args, t_list *a);

#endif
