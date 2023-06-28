/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:17:56 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/28 20:32:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_malloc_error(void)
{
	ft_putstr("Malloc failed.\n");
	exit(EXIT_SUCCESS);
}

void	ft_mallocerror_node(t_node *a_stack, int index)
{
	int		i;

	i = 0;
	while (i < index + 1)
	{
		a_stack = a_stack -> next;
		free(a_stack);
		i++;
	}
	ft_printf("Malloc failed.\n");
	exit(EXIT_FAILURE);
}
