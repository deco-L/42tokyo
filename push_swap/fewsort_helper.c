/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewsort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:05:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/24 14:52:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_fewsort_push(t_node *a_stack, t_node *b_stack, int index)
{
	int	i;
	int	check;
	int	move;

	i = 0;
	move = 0;
	while (i < index)
	{
		check = (a_stack -> next)-> content;
		if (1 <= check && check <= index - 3)
		{
			ft_sort_rule_pab(a_stack, b_stack, 1);
			move++;
			continue ;
		}
		if (move == index - 3)
			break ;
		ft_sort_rule_rab(a_stack, 0);
		i++;
	}
}

void	ft_twoarg_resort(t_node *stack)
{
	t_node	*start;

	start = stack;
	if (stack -> flag)
		stack = stack -> next;
	stack = stack -> next;
	if ((stack -> prev)-> content < stack -> content)
		ft_sort_rule_sab(start, 1);
}

void	ft_threearg_resort(t_node *stack)
{
	t_node	*start;

	start = stack;
	if (stack -> flag)
		stack = stack -> next;
	if (stack -> content < (stack -> next)-> content)
		ft_small_head_resort(start, stack);
	else
		ft_big_head_resort(start, stack);
}
