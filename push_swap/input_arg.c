/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:57:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 17:20:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_input_arg(int index, char **argv, t_node a_stack, int flag)
{
	int		*ccstack;
	int		*sort_stack;

	ccstack = ft_calloc(index, sizeof(int));
	sort_stack = ft_calloc(index, sizeof(int));
	if (ccstack == NULL || sort_stack == NULL)
		ft_malloc_error();
	if (flag)
		ccstack = ft_format_input(ccstack, argv);
	else
		ccstack = ft_input(ccstack, index, argv);
	sort_stack = ft_sort_array(sort_stack, ccstack, index);
	ccstack = ft_cc(ccstack, sort_stack, index);
	ft_make_node(a_stack, index);
	free (ccstack);
	free (sort_stack);
}

	// for (int i = 0; i < index; i++)
		// ft_printf("%d : %d\n", i + 1, ccstack[i]);
	// for (int i = 0; i < index; i++)
	// 	ft_printf("%d : %d\n", i + 1, sort_stack[i]);