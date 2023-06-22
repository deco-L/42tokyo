/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:26:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 16:29:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*ft_sort_rule_sa(t_node *stack)
{
	t_node	*start;
	t_node	*above_stack;
	t_node	*below_stack;

	start = stack;
	if (stack -> flag)
		stack = stack -> next;
	above_stack = stack;
	below_stack = stack -> next;
	start -> next = below_stack;
	(below_stack -> next)-> prev = above_stack;
	above_stack -> prev = below_stack;
	above_stack -> next = below_stack -> next;
	below_stack -> prev = start;
	below_stack -> next = above_stack;
	ft_putstr("sa\n");
	return (start);
}

t_node	*ft_sort_rule_ra(t_node *stack)
{
	t_node	*start;

	start = stack;
	stack = stack -> next;
	(start -> prev)-> next = stack;
	start -> next = stack -> next;
	stack -> next = start;
	stack -> prev = (start -> prev);
	start -> prev = stack;
	ft_putstr("ra\n");
	return (start);
}

t_node	*ft_sort_rule_rra(t_node *stack)
{
	return (stack);
}
