/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:47 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 15:02:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_small_head_sort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content < (stack -> next)-> content)
		return ;
	else if ((stack -> prev)-> content < (stack -> next)-> content)
		ft_putstr("ra\nsa\nrra\n");
	else
		ft_putstr("rra\n");
	return ;
}

void	ft_big_head_sort(t_node *start, t_node *stack)
{
	stack = stack -> next;
	if (stack -> content > (stack -> next)-> content)
		ft_putstr("sa\nrra\n");
	else if ((stack -> prev)-> content > (stack -> next)-> content)
		ft_putstr("ra\n");
	else
		ft_sort_rule_sa(start);
	return ;
}
