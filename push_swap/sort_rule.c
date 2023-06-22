/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:26:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 14:01:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*ft_sort_rule_sa(t_node *stack)
{
	int		number;
	t_node	*above_stack;
	t_node	*below_stack;

	if (stack -> flag)
		stack = stack -> next;
	above_stack = stack;
	below_stack = stack -> next;
	number = above_stack -> content;
	above_stack -> content = below_stack -> content;
	below_stack -> content = number;
	ft_putstr("sa\n");
	return (above_stack);
}

	// ft_printf("stack : point = |%p|, content = |%d|, flag = |%d|, next = |%p|, prev = |%p|\n", stack, stack -> content, stack -> flag, stack -> next, stack -> prev);
	// ft_printf("stack : point = |%p|, content = |%d|, flag = |%d|, next = |%p|, prev = |%p|\n", above_stack, above_stack -> content, above_stack -> flag, above_stack -> next, above_stack -> prev);