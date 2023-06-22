/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:47 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 16:44:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_small_head_sort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content < (stack -> next)-> content)
		return ;
	else if ((stack -> prev)-> content < (stack -> next)-> content)
	{
		ft_sort_rule_ra(start);
		ft_sort_rule_sa(start);
		ft_sort_rule_rra(start);
	}
	else
		ft_sort_rule_rra(start);
	return ;
}

void	ft_big_head_sort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content > (stack -> next)-> content)
	{
		ft_sort_rule_sa(start);
		ft_sort_rule_rra(start);
	}
	else if ((stack -> prev)-> content > (stack -> next)-> content)
		start = ft_sort_rule_ra(start);
	else
		ft_sort_rule_sa(start);
	return ;
}
