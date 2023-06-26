/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:57:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/26 15:40:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*ft_input_arg(int index, char **argv, t_node *a_stack, int flag)
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
	a_stack = ft_make_node(a_stack, ccstack, index);
	free (ccstack);
	return (a_stack);
}

t_node	*ft_make_node(t_node *a_stack, int *ccstack, int index)
{
	int		i;
	t_node	*new;
	t_node	*start;

	i = 0;
	a_stack = ft_mkloop_node(&a_stack, start, i);
	start = a_stack;
	if (!a_stack)
	{
		free (ccstack);
		ft_malloc_error();
	}
	while (i < index)
	{
		new = ft_new_node(a_stack, ccstack[i]);
		if (!new)
			ft_mallocerror_node(start, i);
		ft_nodeadd_back(&a_stack, new);
		i++;
	}
	a_stack = ft_mkloop_node(&a_stack, start, i);
	return (start);
}
