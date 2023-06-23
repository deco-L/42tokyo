/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:45:05 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/23 15:32:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_delete_all_node(t_node *src_stack)
{
	t_node	*start;
	t_node	*stack;

	start = src_stack;
	if (src_stack -> next == NULL)
	{
		free(src_stack);
		return ;
	}
	src_stack = src_stack -> next;
	while (!(src_stack -> flag))
	{
		stack = src_stack;
		src_stack = (src_stack -> next);
		free(stack);
	}
	free(start);
	return ;
}