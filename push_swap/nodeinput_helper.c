/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeinput_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:37:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 20:59:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*ft_mkloop_node(t_node **a_stack, int i)
{
	t_node	*new;
	t_node	*start;

	if (i)
	{
		start = *a_stack;
		while((*a_stack) -> next)
			*a_stack = (*a_stack) -> next;
		(*a_stack) -> next = start;
		start -> prev = *a_stack;
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