/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewsort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:05:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 19:43:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_sort_checker(t_node *stack)
{
	stack = stack -> next;
	while (!(stack -> flag))
	{
		if ((stack -> prev)-> content > stack -> content)
			break;
		stack = stack -> next;
	}
	if (stack -> flag)
		return (1);
	return (0);
}

void	ft_fewsort_push(t_node *a_stack, t_node *b_stack, int index)
{
	int		i;
	t_node	*a_start;
	t_node	*b_start;

	i = 0;
	a_start = a_stack;
	b_start = b_stack;
	while (i < index - 3)
	{
		a_stack = a_stack -> next;
		while (!(a_stack -> flag))
		{
			if (a_stack -> content == i + 1)
				ft_sort_rule_pa(a_start, b_start);
			ft_sort_rule_ra(a_start);
			a_stack = a_stack -> next;
		}
		i++;
	}
	return ;
}

void	ft_fewsort_return(t_node *a_stack, t_node *b_stack, int index)
{
	return ;
}