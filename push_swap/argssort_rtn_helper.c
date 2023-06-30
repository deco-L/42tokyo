/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argssort_rtn_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:35:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/30 22:13:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_rtn_fnbr(t_node *b_stack, int rtnnbr)
{
	int		rab;
	int		rrab;

	rab = ft_serch_rab(b_stack, rtnnbr);
	rrab = ft_serch_rrab(b_stack, rtnnbr);
	ft_last_rtn(b_stack, rab, rrab);
}

int	ft_serch_rab(t_node *b_stack, int rtnnbr)
{
	int		i;
	t_node	*start;

	i = 0;
	start = b_stack;
	while (start -> content != rtnnbr)
	{
		start = start -> next;
		i++;
	}
	return (i);
}

int	ft_serch_rrab(t_node *b_stack, int rtnnbr)
{
	int		i;
	t_node	*start;

	i = 0;
	start = b_stack;
	while (start -> content != rtnnbr)
	{
		start = start -> prev;
		i++;
	}
	return (i);
}

void	ft_last_rtn(t_node *b_stack, int rab, int rrab)
{
	if (rab < rrab)
	{
		while (rab--)
			ft_sort_rule_rab(b_stack, 1);
	}
	else
	{
		while (rrab--)
			ft_sort_rule_rrab(b_stack, 1);
	}
}

// void	ft_rtn_fnbr(t_node *b_stack, int count, int rtnnbr)
// {
// 	int		rab;
// 	int		rrab;
// 	int		flag;
// 	t_node	*start;

// 	flag = 0;
// 	start = b_stack;
// 	rab = ft_serch_rab(b_stack, count, rtnnbr);
// 	rrab = ft_serch_rrab(b_stack, count, rtnnbr);
// 	if (rab && rrab)
// 		ft_last_rtn(b_stack, rab, rrab);
// 	else
// 	{
// 		while (rab--)
// 			ft_sort_rule_rab(b_stack, 1);
// 		while (rrab--)
// 			ft_sort_rule_rrab(b_stack, 1);
// 	}
// }

// int	ft_serch_rab(t_node *b_stack, int count, int rtnnbr)
// {
// 	int		i;
// 	t_node	*start;

// 	i = 0;
// 	start = b_stack;
// 	while (i <= count)
// 	{
// 		if (start -> content == rtnnbr)
// 			return (i);
// 		start = start -> next;
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_serch_rrab(t_node *b_stack, int count, int rtnnbr)
// {
// 	int		i;
// 	t_node	*start;

// 	i = 0;
// 	start = b_stack;
// 	while (i <= count)
// 	{
// 		if (start -> content == rtnnbr)
// 			return (i);
// 		start = start -> prev;
// 		i++;
// 	}
// 	return (0);
// }