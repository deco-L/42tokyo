/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:45:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 10:13:53 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_delete_all_node(t_node *a_stack)
{
	t_node	*start;
	t_node	*stack;

	start = a_stack;
	a_stack = a_stack -> next;
	while (!(a_stack -> flag))
	{
		stack = a_stack;
		a_stack = (a_stack -> next);
		free(stack);
	}
	free(start);
	return ;
}