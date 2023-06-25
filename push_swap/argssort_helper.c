/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argssort_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:49:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/25 18:57:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_argsort_push(t_node *a_stack, t_node *b_stack, int pivot, int group)
{
	int	i;
	int	j;
	int	check;
	int	center;

	i = 0;
	j = 0;
	while (a_stack -> next != a_stack)
	{
		center = (pivot / 2 + j / group + 1) * group;
		check = (a_stack -> next)-> content;
		if ((i / group) * group < check && check <= (i / group + 1) * group)
		{
			i++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
		}
		else if (center < check && check <= center + group)
		{
			j++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
			ft_sort_rule_rab(b_stack, 1);
		}
		else
			ft_sort_rule_rab(a_stack, 0);
	}
}

void	ft_argsort_rtn(t_node *a_stack, t_node *b_stack, int index, int group)
{
	int	i;
	int	j;
	int	surplus;
	int	quotient;

	quotient = index - surplus;
	while (b_stack -> next != b_stack)
	{
		if (!((b_stack -> prev)-> content <= group))
		{
			ft_surplus_rtn(a_stack, b_stack, index, group);
			ft_tail_return(a_stack, b_stack, quotient - (i * group), group);
			i++;
		}
		else
		{
			ft_head_return(a_stack, b_stack, j * group, group);
			j++;
		}
	}
}

void	ft_surplus_rtn(t_node *a_stack, t_node *b_stack, int index, int group)
{
	int	i;
	int	surplus;

	i = 0;
	surplus = index % group;
	while (i < surplus)
	{
		if ((b_stack -> next)-> content == index - i)
		{
			ft_sort_rule_pab(b_stack, a_stack, 1);
			i++;
		}
		else if (index - surplus < (b_stack -> prev)-> content)
		{
			ft_sort_rule_rrb(b_stack, 1);
			continue ;
		}
		else if (index - surplus < (b_stack -> next)-> content)
		{
			ft_sort_rule_rab(b_stack, 1);
			continue ;
		}
	}
}

void	ft_tail_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group)
{
	int	i;

	while (i < group)
	{
		if ((b_stack -> prev)-> content == dividion - i)
		{
			ft_sort_rule_pab(b_stack, a_stack, 1);
			i++;
		}
		else if (divison - group < (b_stack -> prev)-> content)
		{
			ft_sort_rule_rrab(b_stack, 1);
			continue ;
		}
		else if (division  - group < (b_stack -> next)-> )
	}
	return ;
}

void	ft_head_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group)
{
	return ;
}
