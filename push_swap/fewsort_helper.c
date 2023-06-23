/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewsort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:05:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/23 16:35:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_sort_checker(t_node *stack)
{
	stack = stack -> next;
	while (!(stack -> flag))
	{
		if ((stack -> prev)-> content > stack -> content)
			break ;
		stack = stack -> next;
	}
	if (stack -> flag)
		return (1);
	return (0);
}

void	ft_fewsort_push(t_node *a_stack, t_node *b_stack, int index)
{
	int		i;
	int		j;
	int		move;
	t_node	*a_start;

	i = 0;
	move = 0;
	a_start = a_stack;
	while (i < index)
	{
		j = 0;
		while (j < index - 3)
		{
			if ((a_start -> next)-> content == j + 1)
			{
				ft_sort_rule_pab(a_start, b_stack, 1);
				move++;
			}
			j++;
		}
		if (move == index - 3)
			break ;
		ft_sort_rule_rab(a_start, 0);
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
