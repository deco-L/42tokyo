/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:57:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 21:02:25 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_input_arg(int index, char **argv, t_node *a_stack, int flag)
{
	int		*ccstack;
	int		*sort_stack;

	ccstack = ft_calloc(index, sizeof(int));
	sort_stack = ft_calloc(index, sizeof(int));
	if (!ccstack || !sort_stack)
		ft_malloc_error();
	if (flag)
		ccstack = ft_format_input(ccstack, argv);
	else
		ccstack = ft_input(ccstack, index, argv);
	sort_stack = ft_sort_array(sort_stack, ccstack, index);
	ccstack = ft_cc(ccstack, sort_stack, index);
	free (sort_stack);
	a_stack =ft_make_node(a_stack, ccstack, index);
	for (int i = 0; i < index; i++)
		printf("%d\n", a_stack -> content);
	ft_delete_all_node(&a_stack);
	free (ccstack);
}

t_node	*ft_make_node(t_node *a_stack, int *ccstack, int index)
{
	int		i;
	t_node	*new;

	i = 0;
	a_stack = ft_mkloop_node(&a_stack, i);
	if (!a_stack)
	{
		free (ccstack);
		ft_malloc_error();
	}
	while (i < index)
	{
		new = ft_new_node(a_stack, ccstack[i]);
		if (!new)
			ft_mallocerror_node(a_stack, i);
		ft_nodeadd_back(&a_stack, new);
		i++;
	}
	a_stack = ft_mkloop_node(&a_stack, i);
	return (a_stack);
}

	// for (int i = 0; i < index; i++)
		// ft_printf("%d : %d\n", i + 1, ccstack[i]);
	// for (int i = 0; i < index; i++)
	// 	ft_printf("%d : %d\n", i + 1, sort_stack[i]);