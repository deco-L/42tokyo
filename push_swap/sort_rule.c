/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:26:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/08 13:15:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_sort_rule_sab(t_node *stack, int mode)
{
	t_node	*start;
	t_node	*above_stack;
	t_node	*below_stack;

	start = stack;
	stack = stack -> next;
	above_stack = stack;
	below_stack = stack -> next;
	start -> next = below_stack;
	(below_stack -> next)-> prev = above_stack;
	above_stack -> prev = below_stack;
	above_stack -> next = below_stack -> next;
	below_stack -> prev = start;
	below_stack -> next = above_stack;
	if (mode)
	{
		ft_printf("sb\n");
		return ;
	}
	ft_printf("sa\n");
	return ;
}

void	ft_sort_rule_rab(t_node *stack, int mode)
{
	t_node	*start;

	start = stack;
	stack = stack -> next;
	(stack -> next)-> prev = start;
	start -> next = stack -> next;
	(start -> prev)-> next = stack;
	stack -> next = start;
	stack -> prev = (start -> prev);
	start -> prev = stack;
	if (mode)
	{
		ft_printf("rb\n");
		return ;
	}
	ft_printf("ra\n");
	return ;
}

void	ft_sort_rule_rrab(t_node *stack, int mode)
{
	t_node	*start;

	start = stack;
	stack = stack -> prev;
	(stack -> prev)-> next = start;
	(start -> next)-> prev = stack;
	stack -> next = start ->next;
	start -> next = stack;
	start -> prev = stack -> prev;
	stack -> prev = start;
	if (mode)
	{
		ft_printf("rrb\n");
		return ;
	}
	ft_printf("rra\n");
	return ;
}

void	ft_sort_rule_pab(t_node *move_stack, t_node *receive_stack, int mode)
{
	t_node	*move_start;
	t_node	*receive_start;

	move_start = move_stack;
	receive_start = receive_stack;
	if (receive_stack -> next == NULL || receive_stack -> next == receive_stack)
		ft_first_sort_pab(move_stack, receive_stack);
	else
	{
		move_stack = move_stack -> next;
		receive_stack = receive_stack -> next;
		move_start -> next = move_stack -> next;
		(move_stack -> next)-> prev = move_start;
		move_stack -> next = receive_stack;
		move_stack -> prev = receive_start;
		receive_start -> next = move_stack;
		receive_stack -> prev = move_stack;
	}
	if (mode)
	{
		ft_printf("pb\n");
		return ;
	}
	ft_printf("pa\n");
	return ;
}

void	ft_first_sort_pab(t_node *move_stack, t_node *receive_stack)
{
	t_node	*move_start;

	move_start = move_stack;
	move_stack = move_stack -> next;
	move_start -> next = move_stack -> next;
	(move_stack -> next)-> prev = move_start;
	move_stack -> next = receive_stack;
	move_stack -> prev = receive_stack;
	receive_stack -> next = move_stack;
	receive_stack -> prev = move_stack;
	return ;
}
