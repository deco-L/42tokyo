/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argssort_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:49:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/30 22:16:44 by csakamot         ###   ########.fr       */
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
		if (ft_pushcheck_head(check, i, group))
		{
			i++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
		}
		else if (ft_pushcheck_tail(check, center, group))
		{
			j++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
			ft_sort_rule_rab(b_stack, 1);
		}
		else
			ft_sort_rule_rab(a_stack, 0);
	}
}

void	ft_argsort_rtn(t_node *a_stack, t_node *b_stack, int index, int pivot)
{
	int	i;
	int	group;
	int	surplus;
	int	quotient;

	i = 0;
	group = index / pivot;
	surplus = index - (group * pivot);
	quotient = index - surplus;
	ft_surpls_rtn(a_stack, b_stack, index, surplus);
	while (b_stack -> next != b_stack)
	{
		if (!((b_stack -> prev)-> content <= group))
		{
			ft_tail_return(a_stack, b_stack, quotient - (i * group), group);
			i++;
		}
		else
		{
			ft_head_return(a_stack, b_stack, quotient - (i * group), group);
			i++;
		}
	}
}

void	ft_surpls_rtn(t_node *a_stack, t_node *b_stack, int index, int surpls)
{
	int		i;

	i = 0;
	while (i < surpls)
	{
		if ((b_stack -> next)-> content == index - i)
		{
			ft_sort_rule_pab(b_stack, a_stack, 0);
			i++;
			continue ;
		}
		ft_rtn_fnbr(b_stack, index - i);
	}
}

void	ft_tail_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group)
{
	int	i;

	i = 0;
	while (i < group)
	{
		if ((b_stack -> next)-> content == rtnnbr - i)
		{
			ft_sort_rule_pab(b_stack, a_stack, 0);
			i++;
			continue ;
		}
		ft_rtn_fnbr(b_stack, rtnnbr - i);
	}
}

void	ft_head_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group)
{
	int	i;

	i = 0;
	while (i < group)
	{
		if ((b_stack -> next)-> content == rtnnbr - i)
		{
			ft_sort_rule_pab(b_stack, a_stack, 0);
			i++;
			continue ;
		}
		ft_rtn_fnbr(b_stack, rtnnbr - i);
	}
}

// void	ft_surpls_rtn(t_node *a_stack, t_node *b_stack, int index, int surpls)
// {
// 	int	i;
// 	int	mode;

// 	i = 0;
// 	mode = 1;
// 	while (i < surpls)
// 	{
// 		if ((b_stack -> next)-> content == index - i)
// 		{
// 			ft_sort_rule_pab(b_stack, a_stack, 0);
// 			i++;
// 			continue ;
// 		}
// 		if (index - surpls < (b_stack -> prev)-> content && mode == 1)
// 		{
// 			ft_sort_rule_rrab(b_stack, 1);
// 			continue ;
// 		}
// 		else if (index - surpls < (b_stack -> next)-> content && mode == -1)
// 		{
// 			ft_sort_rule_rab(b_stack, 1);
// 			continue ;
// 		}
// 		mode *= -1;
// 	}
// }