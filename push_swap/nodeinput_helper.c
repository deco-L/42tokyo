/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeinput_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:37:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 01:42:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*ft_mkloop_node(t_node **a_stack, t_node *start, int i)
{
	t_node	*new;

	if (i)
	{
		ft_printf("start : %p, **a_stack: %p\n", start, *a_stack);
		(*a_stack) -> next = start;
		ft_printf("start -> prev : %p, a_stack -> next : %p\n", start -> prev, (*a_stack) -> next);
		return (*a_stack);
	}
	else
	{
	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new -> content = 0;
	new -> next = NULL;
	new -> prev = NULL;
	new -> flag = 1;
	return (new);
	}
}

t_node	*ft_new_node(t_node *a_stack, int content)
{
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	new -> prev = NULL;
	new -> flag = 0;
	return (new);
}

void	ft_nodeadd_back(t_node **a_stack, t_node *new)
{
	while ((*a_stack) -> next)
		*a_stack = ((*a_stack) -> next);
	(*a_stack) -> next = new;
	new -> prev = *a_stack;
}