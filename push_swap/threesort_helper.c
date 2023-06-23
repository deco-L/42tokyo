/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:47 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/23 16:18:26 by csakamot         ###   ########.fr       */
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
		ft_sort_rule_rab(start, 0);
		ft_sort_rule_sab(start, 0);
		ft_sort_rule_rrab(start, 0);
	}
	else
		ft_sort_rule_rrab(start, 0);
	return ;
}

void	ft_big_head_sort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content > (stack -> next)-> content)
	{
		ft_sort_rule_sab(start, 0);
		ft_sort_rule_rrab(start, 0);
	}
	else if ((stack -> prev)-> content > (stack -> next)-> content)
		ft_sort_rule_rab(start, 0);
	else
		ft_sort_rule_sab(start, 0);
	return ;
}

void	ft_small_head_resort(t_node *start, t_node *stack)
{
		stack = stack -> next;
	if (stack -> content < (stack -> next)-> content)
	{
		ft_sort_rule_sab(start, 1);
		ft_sort_rule_rrab(start, 1);
	}
	else if ((stack -> prev)-> content < (stack -> next)-> content)
		ft_sort_rule_rab(start, 1);
	else
		ft_sort_rule_sab(start, 1);
	return ;
}

void	ft_big_head_resort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content > (stack -> next)-> content)
		return ;
	else if ((stack -> prev)-> content > (stack -> next)-> content)
	{
		ft_sort_rule_rab(start, 1);
		ft_sort_rule_sab(start, 1);
		ft_sort_rule_rrab(start, 1);
	}
	else
		ft_sort_rule_rrab(start, 1);
	return ;
}
